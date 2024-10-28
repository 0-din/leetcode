/* Write your T-SQL query statement below */

select  x.sell_date,
        sum(num_sold) num_sold,
        string_agg(product, ',') within group(order by product) as products
from
(
    select  sell_date,
            count(distinct product) num_sold,
            product
    from activities
    group by sell_date, product
) x
group by x.sell_date
order by x.sell_date