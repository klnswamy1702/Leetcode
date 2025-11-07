-- Last updated: 07/11/2025, 13:41:29
# Write your MySQL query statement below

# select a1.machine_id, ROUND(AVG(a2.timestamp - a1.timestamp),3) as processing_time
# from Activity a1
# join Activity a2
# on a1.process_id=a2.process_id
# and a1.machine_id=a2.machine_id
# and a1.timestamp<a2.timestamp
# group by a1.machine_id;

# | machine_id | processing_time |
# | ---------- | --------------- |
# | 0          | 0.894           |
# | 1          | 0.995           |
# | 2          | 1.456           |

# SELECT s.machine_id, ROUND(AVG(e.timestamp-s.timestamp), 3) AS processing_time
# FROM Activity s JOIN Activity e ON
#     s.machine_id = e.machine_id AND s.process_id = e.process_id AND
#     s.activity_type = 'start' AND e.activity_type = 'end'
# GROUP BY s.machine_id

SELECT machine_id, ROUND((SUM(CASE WHEN activity_type = 'end' THEN timestamp END)-SUM(CASE WHEN activity_type = 'start' THEN timestamp END))/COUNT(DISTINCT process_id), 3) processing_time
FROM Activity
GROUP BY 1