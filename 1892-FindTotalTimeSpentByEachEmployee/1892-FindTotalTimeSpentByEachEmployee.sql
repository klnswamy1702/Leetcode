-- Last updated: 07/11/2025, 13:41:21
# Write your MySQL query statement below
# Write your MySQL query statement below
# select
#     event_day as day, emp_id
#     , sum(out_time) - sum(in_time) as total_time
# from 
#     Employees
# group by 
#     event_day, emp_id

select
    event_day as day, emp_id
    , sum(out_time-in_time) as total_time
from 
    Employees
group by 
    event_day, emp_id