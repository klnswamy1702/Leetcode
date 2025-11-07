-- Last updated: 07/11/2025, 13:41:09
# Write your MySQL query statement below


# select s.user_id, round(avg(if(c.action="confirmed",1,0)),2) as confirmation_rate
# from Signups as s left join Confirmations as c on s.user_id= c.user_id group by user_id;

# SELECT 
#   s.user_id,
#   ROUND(AVG(CASE WHEN action = 'confirmed' THEN 1.00 ELSE 0.00 END),2) AS confirmation_rate
# FROM Signups s LEFT JOIN Confirmations c ON s.user_id = c.user_id
# GROUP BY s.user_id

# Write your MySQL query statement below

# SELECT s.user_id, 
#   ROUND(AVG(IF(c.action='confirmed',1,0)),2) as confirmation_rate 
# FROM Signups s
# LEFT JOIN Confirmations c using (user_id)
# GROUP BY s.user_id

select
    s.user_id,
    ifnull(round(sum(action='confirmed')/sum(action='confirmed' or action='timeout'), 2), 0) as confirmation_rate
from signups s
left join confirmations c
on s.user_id = c.user_id
group by s.user_id