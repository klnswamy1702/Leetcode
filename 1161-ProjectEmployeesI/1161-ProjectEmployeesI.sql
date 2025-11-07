-- Last updated: 07/11/2025, 13:42:57
# Write your MySQL query statement below

# select 
# project_id,
# round(sum(e.experience_years) / count(e.experience_years),2) as average_years
# from Project p
# join Employee e on p.employee_id = e.employee_id
# group by project_id

# SELECT p.project_id,ROUND(AVG(e.experience_years),2) AS 'average_years'
# FROM Employee e
# JOIN Project p
# ON e.employee_id = p.employee_id
# GROUP BY p.project_id;

# SELECT             p.project_id,
#                    ROUND(AVG(e.experience_years), 2) AS average_years
# FROM               Project AS p
# INNER JOIN         Employee AS e
# ON                 p.employee_id = e.employee_id
# GROUP BY           p.project_id

# select project_id, round(sum(experience_years)/count(*),2) as average_years 
# from project
# join employee using (employee_id)
# group by project_id 

SELECT p.project_id,
ROUND(AVG(e.experience_years),2) AS average_years
FROM Project p
LEFT JOIN Employee e
ON p.employee_id = e.employee_id
GROUP BY p.project_id;