/* Write your T-SQL query statement below */



select t.id, 
        (case 
            when t.p_id is null then 'Root'
            when (select count(*) from tree x where x.p_id = t.id) < 1 then 'Leaf'
            else 'Inner'
        end) type
from tree t
