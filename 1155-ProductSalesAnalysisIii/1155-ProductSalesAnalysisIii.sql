-- Last updated: 07/11/2025, 13:42:59
# Write your MySQL query statement below
# SELECT product_id, year AS first_year, quantity, price
# FROM Sales
# WHERE (product_id, year) IN (
# SELECT product_id, MIN(year) as year
# FROM Sales
# GROUP BY product_id) ;

select
    product_id,
    year as first_year,
    quantity,
    price
from Sales
where (product_id, year) in (select product_id, min(year) from Sales group by 1)