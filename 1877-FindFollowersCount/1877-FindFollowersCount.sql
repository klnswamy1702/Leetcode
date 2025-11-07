-- Last updated: 07/11/2025, 13:41:25
# Write your MySQL query statement below

SELECT user_id,COUNT(DISTINCT(follower_id)) AS followers_count
FROM followers
GROUP BY user_id

