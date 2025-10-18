# Write your MySQL query statement below
select d.name as Department,e.name as Employee,e.salary as Salary from (
    select departmentId,name,salary,dense_rank()
    over(
        partition by departmentId order by salary desc
        ) as rnk
    from employee
) e
join department d on e.departmentId = d.id
where rnk <= 3
order by e.salary desc;