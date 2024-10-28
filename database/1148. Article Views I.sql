/* Write your T-SQL query statement below */

select distinct author_id id
from Views v
where author_id in (select viewer_id
                    from Views
                    where article_id = v.article_id)
order by author_id