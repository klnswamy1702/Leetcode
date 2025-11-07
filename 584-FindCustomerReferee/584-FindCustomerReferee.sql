-- Last updated: 07/11/2025, 13:44:28
# Write your MySQL query statement below
# select name from Customer
# where referee_id!=2 or referee_id is null;

SELECT name
FROM Customer
WHERE COALESCE(referee_id,0) <> 2;