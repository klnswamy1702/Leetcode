-- SELECT 
--   mgr.employee_id, 
--   mgr.name, 
--   COUNT(emp.employee_id) AS reports_count, 
--   ROUND(
--     AVG(emp.age)
--   ) AS average_age 
-- FROM 
--   employees emp 
--   JOIN employees mgr ON emp.reports_to = mgr.employee_id 
-- GROUP BY 
--   employee_id 
-- ORDER BY 
--   employee_id


SELECT 
  reports_to AS employee_id, 
  (
    SELECT 
      name 
    FROM 
      employees e1 
    WHERE 
      e.reports_to = e1.employee_id 
  ) AS name, 
  COUNT(reports_to) AS reports_count, 
  ROUND(
    AVG(age)
  ) AS average_age 
FROM 
  employees e 
GROUP BY 
  reports_to 
HAVING 
  reports_count > 0 
ORDER BY 
  employee_id