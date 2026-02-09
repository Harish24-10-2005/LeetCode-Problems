# Write your MySQL query statement below
SELECT product_id, YEAR AS first_year, quantity, price
FROM (
    SELECT *,
    ROW_NUMBER() OVER(PARTITION BY PRODUCT_ID ORDER BY YEAR) AS RN
    FROM Sales
) AS S
WHERE RN = 1;
