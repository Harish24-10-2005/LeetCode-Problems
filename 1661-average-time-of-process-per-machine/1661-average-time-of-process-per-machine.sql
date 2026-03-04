# Write your MySQL query statement below
select machine_id,ROUND(sum(
    case
    when activity_type = 'start' then (-timestamp)
    else timestamp
    end
    )/count(Distinct process_id),3) as processing_time
from Activity
group by machine_id
