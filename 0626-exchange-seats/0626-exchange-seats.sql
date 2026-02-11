# Write your MySQL query statement below
SELECT ID ,
    CASE
        WHEN (ID % 2 = 0) THEN PRENAME
        WHEN (ID % 2 != 0) AND NXTNAME IS NOT NULL THEN NXTNAME
        ELSE student
    END AS student
FROM(
    SELECT *,
    LAG(STUDENT) OVER(ORDER BY ID) AS PRENAME,
    LEAD(STUDENT) OVER(ORDER BY ID) AS NXTNAME
    FROM Seat
) AS S