/* Write your T-SQL query statement below */

select isnull(e.employee_id, s.employee_id) employee_id 
from Employees e
full outer join Salaries s on s.employee_id = e.employee_id
where e.employee_id is null or s.employee_id is null
order by employee_id