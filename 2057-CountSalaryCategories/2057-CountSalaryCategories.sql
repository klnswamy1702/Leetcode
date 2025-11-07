-- Last updated: 07/11/2025, 13:41:14
# Write your MySQL query statement below
# select "Low Salary" as category,
# sum(case when income<20000 then 1 else 0 end) as accounts_count
# from Accounts
# union
# select "Average Salary" category,
# sum(case when income >= 20000 and income <= 50000 then 1 else 0 end) as accounts_count
# from Accounts
# union
# select "High Salary" category,
# sum(case when income>50000 then 1 else 0 end) as accounts_count
# from Accounts

SELECT "Low Salary" AS Category,
SUM(income<20000) AS accounts_count
FROM Accounts
UNION
SELECT  "Average Salary" Category,
SUM(income BETWEEN 20000 AND 50000) AS accounts_count
FROM Accounts
UNION
SELECT "High Salary" category,
SUM(income>50000) AS accounts_count
FROM Accounts