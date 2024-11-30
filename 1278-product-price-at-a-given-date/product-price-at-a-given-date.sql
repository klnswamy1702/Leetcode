-- -- Approach 1: Divide cases by using UNION ALL
-- SELECT
--   product_id,
--   10 AS price
-- FROM
--   Products
-- GROUP BY
--   product_id
-- HAVING
--   MIN(change_date) > '2019-08-16'
-- UNION ALL
-- SELECT
--   product_id,
--   new_price AS price
-- FROM
--   Products
-- WHERE
--   (product_id, change_date) IN (
--     SELECT
--       product_id,
--       MAX(change_date)
--     FROM
--       Products
--     WHERE
--       change_date <= '2019-08-16'
--     GROUP BY
--       product_id
--   )

-- -- Approach 2: Use the window function

SELECT
  product_id,
  IFNULL (price, 10) AS price
FROM
  (
    SELECT DISTINCT
      product_id
    FROM
      Products
  ) AS UniqueProducts
  LEFT JOIN (
    SELECT DISTINCT
      product_id,
      FIRST_VALUE (new_price) OVER (
        PARTITION BY
          product_id
        ORDER BY
          change_date DESC
      ) AS price
    FROM
      Products
    WHERE
      change_date <= '2019-08-16'
  ) AS LastChangedPrice USING (product_id);