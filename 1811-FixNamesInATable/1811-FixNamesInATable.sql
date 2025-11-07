-- Last updated: 07/11/2025, 13:41:31
# Select user_id, CONCAT(UPPER(SUBSTRING(name,1,1)),LOWER(SUBSTRING(name,2))) as name from Users
# order by user_id;

# Write your MySQL query statement below
# SELECT user_id, CONCAT(UCASE(SUBSTRING(name, 1, 1)), LCASE(SUBSTRING(name, 2))) AS name
# FROM Users
# ORDER BY user_id;

select user_id
    , concat(
        upper(substring(name,1,1)), lower(substring(name,2,length(name)))
    ) name
from Users
order by user_id