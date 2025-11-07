-- Last updated: 07/11/2025, 13:44:12
# Write your MySQL query statement below

UPDATE salary SET sex =
CASE sex
    WHEN 'm' THEN 'f'
    ELSE 'm'
END;

# update salary
# set sex=if(sex='m','f','m');