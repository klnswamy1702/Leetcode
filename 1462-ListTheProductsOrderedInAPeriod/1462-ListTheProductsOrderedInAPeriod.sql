-- Last updated: 07/11/2025, 13:42:24
# Write your MySQL query statement below

# select p.product_name,
# sum(o.unit) as unit
# from Products p
# join Orders o
# on p.product_id = o.product_id
# where Left(order_date, 7) = '2020-02'
# group by p.product_name
# having sum(o.unit) >= 100

# select product_name,sum(unit) as unit
# from Products a
# left join Orders b on a.product_id = b.product_id
# where month(order_date) = 2 and year(order_date) = '2020'
# group by a.product_id
# Having unit >=100

# Write your MySQL query statement below

SELECT p.product_name AS product_name, sum(o.unit) AS unit FROM Products p
JOIN Orders o USING (product_id)
WHERE YEAR(o.order_date)='2020' AND MONTH(o.order_date)='02'
GROUP BY p.product_id
HAVING SUM(o.unit)>=100