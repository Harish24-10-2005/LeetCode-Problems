# Write your MySQL query statement below
select product_id,product_name
from Product 
where product_id in (
    select distinct product_id
    from Sales
    where LEFT(sale_date,4) = "2019"
    group by product_id
    having max(sale_date) between "2019-01-01" and "2019-03-31"
)