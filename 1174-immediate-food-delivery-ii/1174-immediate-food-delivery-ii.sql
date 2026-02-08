# Write your MySQL query statement below
SELECT ROUND((SUM(order_date =customer_pref_delivery_date)/COUNT(*)) * 100,2) AS immediate_percentage
FROM (
    SELECT
        order_date,
        customer_pref_delivery_date,
        ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) AS RN
    FROM Delivery
) AS T
WHERE RN = 1