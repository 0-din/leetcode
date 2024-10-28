/* Write your T-SQL query statement below */


with cte as
(
    select id, salary, departmentId
    from Employee
)
, cte2 as
( 
    select salary, departmentId, row_number() over (partition by departmentId order by salary desc) as indx
    from cte
    group by salary, departmentId
)

select d.name Department, e.name Employee, e.salary Salary
from cte2
left join Employee e on cte2.departmentId = e.departmentId and cte2.salary = e.salary
left join Department d on d.id = cte2.departmentId
where cte2.indx < 4