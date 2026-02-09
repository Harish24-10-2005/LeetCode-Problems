# Write your MySQL query statement below
select person_name
from(
    select *,
    sum(weight) over (order by turn) as cs
    from Queue
)as t
where cs <= 1000
order by cs desc
LIMIT 1