# Write your MySQL query statement below
with a as(
    select requester_id, count(requester_id) as cnt
    from RequestAccepted
    group by requester_id
),
b as (
    select accepter_id as requester_id, count(accepter_id) as cnt
    from RequestAccepted
    group by accepter_id
),
full as(
    select * from a
    union all
    select * from b
)
-- select requester_id as id , sum(coalesce(cnt,0) + coalesce(cnt1,0)) as num
-- from full
select requester_id as id,sum(cnt) as num
from full
group by requester_id
order by num desc
limit 1
-- select * from b
