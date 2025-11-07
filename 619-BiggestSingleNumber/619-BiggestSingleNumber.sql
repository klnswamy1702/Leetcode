-- Last updated: 07/11/2025, 13:44:14
# Write your MySQL query statement below


select(
  select num
  from MyNumbers
  group by num
  having count(*) = 1
  order by num desc limit 1
) as num;

# SELECT num
# FROM MyNumbers
# GROUP BY num
# HAVING count(*) = 1

# UNION ALL
# SELECT NULL

# ORDER BY num DESC
# LIMIT 1;