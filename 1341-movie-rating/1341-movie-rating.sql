# Write your MySQL query statement below
-- WITH RES1 AS(
(
    SELECT U.NAME AS RESULTS
    FROM USERS U JOIN (
        SELECT COUNT(*) AS NO, USER_ID
        FROM MovieRating
        GROUP BY USER_ID
    ) AS R ON U.USER_ID = R.USER_ID
    ORDER BY R.NO DESC, U.name
    LIMIT 1
-- ),
)
    UNION ALL 
(
-- RES2 AS(
    SELECT M.title AS RESULTS
    FROM MOVIES M JOIN (
        SELECT AVG(RATING) AS AVG_RATE, MOVIE_ID
        FROM MovieRating
        WHERE LEFT(created_at,7) = '2020-02'
        GROUP BY MOVIE_ID
    ) AS R ON M.MOVIE_ID = R.MOVIE_ID
    ORDER BY R.AVG_RATE DESC, M.TITLE
    LIMIT 1
)
-- SELECT * FROM RES1
-- UNION ALL 
-- SELECT * FROM RES2