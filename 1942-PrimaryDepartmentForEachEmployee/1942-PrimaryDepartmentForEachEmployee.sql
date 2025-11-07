-- Last updated: 07/11/2025, 13:41:20
# Write your MySQL query statement below
# select employee_id,
#        coalesce(max(case when primary_flag='Y' then department_id else null end),max(department_id)) department_id
#   from employee t
#   group by employee_id

SELECT employee_id, department_id 
FROM Employee
WHERE primary_flag = 'Y'
UNION
SELECT employee_id, department_id 
FROM Employee 
GROUP BY employee_id
HAVING COUNT(employee_id) = 1