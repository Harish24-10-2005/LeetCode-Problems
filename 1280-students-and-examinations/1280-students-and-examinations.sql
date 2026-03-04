# Write your MySQL query statement below
with a as(
    select *,count(*) as attended_exams
    from Examinations
    group by student_id ,subject_name
) ,
b as (
    select * 
    from Students as st cross join Subjects as sub
)

select b.student_id ,b.student_name ,b.subject_name ,coalesce(a.attended_exams,0) as attended_exams
from b left join a 
on b.student_id = a.student_id
and
b.subject_name = a.subject_name
order by b.student_id,b.subject_name