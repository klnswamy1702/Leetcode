SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance i
JOIN
   (
   SELECT tiv_2015
   FROM Insurance
   GROUP BY tiv_2015
   HAVING COUNT(DISTINCT pid) > 1
   )t0
ON i.tiv_2015 = t0.tiv_2015
JOIN
   (
   SELECT CONCAT(lat, lon) lat_lon
   FROM Insurance
   GROUP BY CONCAT(lat, lon)
   HAVING COUNT(DISTINCT pid) = 1
   )t1
ON CONCAT(i.lat, i.lon) = t1.lat_lon


-- -- Approach 2
-- SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
-- FROM (
--    SELECT *,
--        COUNT(*)OVER(PARTITION BY tiv_2015) AS tiv_2015_cnt,
--        COUNT(*)OVER(PARTITION BY lat, lon) AS loc_cnt
--    FROM Insurance
--    )t0
-- WHERE tiv_2015_cnt > 1
-- AND loc_cnt = 1