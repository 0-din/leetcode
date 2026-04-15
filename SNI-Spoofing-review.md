# Code Review: patterniha/SNI-Spoofing

Date: 2026-04-15
Repository: https://github.com/patterniha/SNI-Spoofing

## Scope and method

I reviewed the repository by reading source files through GitHub web/raw views (the runtime environment could not clone from GitHub due to a CONNECT 403 restriction). Findings below are based on the visible code in:

- `main.py`
- `fake_tcp.py`
- `injecter.py`
- `monitor_connection.py`
- `utils/network_tools.py`
- `utils/packet_templates.py`
- `config.json`
- `requirements.txt`
- `README.md`

## High-priority findings

### 1) `sock_sendall` return value is misused (runtime logic bug)

`main.py` stores the result of `await loop.sock_sendall(...)` into `sent_len` and then compares it to `len(data)`.

In asyncio, `sock_sendall` returns `None` on success, so this check always fails and the code enters the exception path. This can cause premature connection teardown and unstable forwarding.

**Impact:** frequent relay disruption and false error handling.

**Fix:** remove the length check and treat successful await as success.

---

### 2) Source port is read before `connect` (incorrect flow keying)

In `main.py`, `src_port = outgoing_sock.getsockname()[1]` is read before calling `sock_connect`.

For an unconnected socket bound with port `0`, the effective ephemeral source port may not be finalized until connect/send. Using this early value to build the connection ID can desynchronize packet tracking in `FakeTcpInjector`.

**Impact:** packet-to-connection mismatch, dropped/ignored packets, intermittent failure.

**Fix:** obtain the local port after successful `sock_connect` (`getsockname` again), then build/register the connection key.

---

### 3) Multiple `sys.exit(...)` calls inside connection handlers (process-level DoS risk)

`main.py` and `fake_tcp.py` use `sys.exit(...)` in non-fatal or packet-specific paths (e.g., unknown bypass mode, impossible direction, relay error).

A malformed packet/state transition can terminate the entire process rather than isolating a single connection.

**Impact:** one bad flow may kill the whole service.

**Fix:** replace `sys.exit(...)` with structured exceptions/logging and per-connection teardown.

## Medium-priority findings

### 4) Shared mutable connection map without explicit synchronization

`fake_injective_connections` is written in asyncio tasks and read from the WinDivert injector thread.

Python dict ops are atomic at bytecode level, but cross-thread iteration/update patterns can still create race windows and brittle behavior.

**Impact:** intermittent KeyError/race edge cases under load.

**Fix:** wrap access in a lock or use thread-safe coordination (queue/event-driven ownership by one thread).

---

### 5) Hard-coded packet template and fragile size math

`utils/packet_templates.py` builds ClientHello from a static hex template and computes padding with `219 - len(target_sni)`.

Long SNI values can make this negative, raising runtime errors; static offsets are also brittle across template changes.

**Impact:** malformed handshake generation and runtime exceptions.

**Fix:** validate SNI length bounds and generate extensions/lengths from structured TLS builders instead of static offsets.

---

### 6) Minimal documentation and operational safeguards

`README.md` is minimal and there is no explicit validation of `config.json` values (e.g., bad IP, too-long SNI, invalid port ranges).

**Impact:** high operator error rate and hard-to-debug failures.

**Fix:** add startup validation with clear error messages; extend README with prerequisites, platform constraints (WinDivert/Windows), and troubleshooting.

## Positive notes

- Clear separation between packet monitor state (`MonitorConnection`) and injector behavior (`FakeTcpInjector`).
- Interface discovery helper in `utils/network_tools.py` is concise.
- Config-driven host/port/SNI is a good start for flexibility.

## Suggested hardening checklist

1. Replace all `sys.exit` in non-top-level code with controlled exceptions.
2. Fix `sock_sendall` success logic.
3. Register flow tuple only after connect completes and final local port is known.
4. Add synchronization strategy for cross-thread connection map access.
5. Validate config at startup (IP format, port range, SNI length constraints).
6. Add structured logging (debug/info/error) for packet state transitions.
7. Add reproducible tests for handshake-state transitions and failure paths.
