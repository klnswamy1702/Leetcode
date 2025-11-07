-- Last updated: 07/11/2025, 13:41:04
# Write your MySQL query statement below
SELECT employee_id FROM Employees
WHERE manager_id NOT IN (SELECT employee_id FROM Employees)
AND salary < 30000
ORDER BY employee_id;