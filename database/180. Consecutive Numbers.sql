/* Write your T-SQL query statement below */

select distinct num ConsecutiveNums
from logs
where num = (select num from logs l
             where l.id = logs.id + 1
                    and num = (select num from logs l1
                               where l1.id = l.id + 1))