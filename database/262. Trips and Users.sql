/* Write your T-SQL query statement below */

SELECT t.request_at AS Day, ROUND(cast(SUM(IIF(t.status <> 'completed', 1, 0)) as decimal(10, 2)) / cast(COUNT(*) as decimal(10, 2)), 2) AS 'Cancellation Rate'
	FROM trips t
JOIN users u ON t.client_id = u.users_id
JOIN users d ON t.driver_id = d.users_id
WHERE u.banned = 'No' AND d.banned = 'No' AND t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY  t.request_at