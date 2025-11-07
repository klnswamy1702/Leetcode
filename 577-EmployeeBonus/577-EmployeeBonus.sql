-- Last updated: 07/11/2025, 13:44:27
# Write your MySQL query statement below

# SELECT name, bonus
# FROM Employee LEFT JOIN Bonus USING(empId)
# WHERE COALESCE(bonus, 0) < 1000; 

# select E.name, B.bonus
# from Employee as E LEFT JOIN Bonus as B
# on E.empId= B.empId
# where B.bonus < 1000 or B.bonus is NULL;

select E.name, B.bonus
from Employee as E LEFT JOIN Bonus as B
on E.empId= B.empId
where COALESCE(bonus, 0) < 1000;