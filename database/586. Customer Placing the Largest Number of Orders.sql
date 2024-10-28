/* Write your T-SQL query statement below */

select customer_number
from orders
group by customer_number
having count(order_number) = (select max(n)
                                from
                                (select customer_number, count(order_number) n
                                from orders
                                group by customer_number) as tmp)