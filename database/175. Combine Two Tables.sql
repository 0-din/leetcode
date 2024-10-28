/* Write your T-SQL query statement below */

select p.firstName, p.lastName, a.city, a.state
from Person p
left outer join Address a on a.personId = p.personId
