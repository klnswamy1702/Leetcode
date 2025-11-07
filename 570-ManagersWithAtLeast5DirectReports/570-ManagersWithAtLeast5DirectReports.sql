-- Last updated: 07/11/2025, 13:44:29
# Write your MySQL query statement below

select name from employee 
where id in 
(select managerId from Employee
group by managerId
having count(managerId)>=5) 

# Write your MySQL query statement below
# Select m.name
# from employee as e
# inner join employee as m
# on e.managerId=m.id
# group by e.managerId 
# having count(e.id)>=5


# select distinct m.name as name
# from employee e join employee m
# on m.id = e.managerid
# group by m.id
# having count(*) >= 5