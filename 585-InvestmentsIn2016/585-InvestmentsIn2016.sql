-- Last updated: 07/11/2025, 13:44:26
# Write your MySQL query statement below

# select round(sum(TIV_2016),2) as TIV_2016
# from insurance a
# where 1 = (select count(*) from insurance b where a.LAT=b.LAT and a.LON=b.LON) 
# and 1 < (select count(*) from insurance c where a.TIV_2015=c.TIV_2015)  ;

SELECT ROUND(SUM(TIV_2016),2) AS TIV_2016 FROM Insurance a
WHERE EXISTS (SELECT * FROM Insurance WHERE PID <> a.PID AND TIV_2015 = a.TIV_2015)
AND NOT EXISTS (SELECT * FROM Insurance WHERE PID <> a.PID AND (LAT,LON) = (a.LAT,a.LON));