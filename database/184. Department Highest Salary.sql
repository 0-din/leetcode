/* Write your T-SQL query statement below */

select d.name Department, e.name Employee, e.salary Salary
from Employee e
join Department d on d.id = e.departmentId
join (select departmentId, max(salary) msalary
      from Employee
      group by departmentId) as e1 on e.departmentId = e1.departmentId
                                    and e.salary = e1.msalary