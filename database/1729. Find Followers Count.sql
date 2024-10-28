/* Write your T-SQL query statement below */

select user_id, count(user_id) followers_count
from Followers
group by user_id