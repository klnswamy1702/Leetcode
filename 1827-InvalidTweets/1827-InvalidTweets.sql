-- Last updated: 07/11/2025, 13:41:28

SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15
