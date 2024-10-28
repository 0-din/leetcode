/* Write your T-SQL query statement below */

select name
from salesperson s
where s.sales_id not in
(
    select sales_id
    from orders
    where com_id in (select com_id from company where name = 'RED')
)

