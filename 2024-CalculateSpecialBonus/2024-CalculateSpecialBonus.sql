-- Last updated: 07/11/2025, 13:41:17
# Write your MySQL query statement below

# select employee_id , salary as bonus 
# from employees 
# where employee_id%2 <>0 and name not like 'M%'

  #  select employee_id , 
  #  case when employee_id%2 <>0 and name not like 'M%' then salary 
  #  else 0
  #  end 
  #  as bonus
  #  from employees
  #  order by employee_id;

select 
    employee_id,
    if(employee_id%2!=0 and name NOT LIKE 'M%',salary,0) as bonus 
from Employees 
order by employee_id