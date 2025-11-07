-- Last updated: 07/11/2025, 13:43:03
# Write your MySQL query statement below

# Write your MySQL query statement below

# SELECT  customer_id FROM Customer GROUP BY customer_id
# HAVING COUNT(distinct product_key) = (SELECT COUNT(product_key) FROM Product)

# SELECT DISTINCT customer_id FROM Customer WHERE customer_id NOT IN (
# SELECT customer_id FROM (
# SELECT DISTINCT * FROM 
# (SELECT DISTINCT customer_id FROM Customer) C
# CROSS JOIN Product P) C2
# WHERE (customer_id,product_key) NOT IN (SELECT customer_id,product_key FROM Customer));

SELECT                                      
    customer_id
FROM Customer
GROUP BY customer_id
HAVING SUM(DISTINCT product_key) = (
    SELECT
        SUM(product_key)
    FROM Product
); 