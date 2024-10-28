/* Write your T-SQL query statement below */
select name Employee
from Employee e
where e.salary > (select salary from Employee m where m.Id = e.managerId)