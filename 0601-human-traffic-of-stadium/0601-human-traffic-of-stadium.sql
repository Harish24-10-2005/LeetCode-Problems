# Write your MySQL query statement below
with g as(
    select * , id - row_number() over (order by id) as grp
    from stadium
    where people >= 100
)
SELECT s.id ,s.visit_date,s.people
from stadium as s join g on s.id = g.id 
where grp in (
    select grp
    from (
        select *,count(*) over (partition by grp order by id) as cnt
        from g
    ) as a
    where cnt >= 3
)
