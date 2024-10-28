
select ISNULL((SELECT DISTINCT
    Salary
FROM
    Employee
ORDER BY Salary DESC
offset 1 row fetch next 1 rows only), null) as SecondHighestSalary