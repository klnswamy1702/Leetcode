-- Last updated: 07/11/2025, 13:41:12
# Write your MySQL query statement below
SELECT
    user_id,
    MAX(time_stamp) AS last_stamp 
    
FROM Logins
WHERE YEAR(time_stamp) = 2020 
GROUP BY user_id;
