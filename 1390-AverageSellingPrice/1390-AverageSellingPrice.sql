-- Last updated: 07/11/2025, 13:42:38
# Write your MySQL query statement below

# Write your MySQL query statement below
# SELECT a.product_id,ROUND(SUM(b.units*a.price)/SUM(b.units),2) as average_price
# FROM Prices as a
# JOIN UnitsSold as b
# ON a.product_id=b.product_id AND (b.purchase_date BETWEEN a.start_date AND a.end_date)
# GROUP BY product_id;

# select prices.product_id, ROUND(SUM(price * units) / SUM(units), 2) as average_price
# from Prices join UnitsSold 
# on prices.product_id = unitssold.product_id
# and purchase_date between start_date and end_date
# group by product_id


select prices.product_id, ROUND(SUM(price * units) / SUM(units), 2) as average_price
from Prices join UnitsSold 
on prices.product_id = unitssold.product_id
and purchase_date between start_date and end_date
group by product_id

# Do upvote if you like the solution.
# Do upvote if you like the solution.