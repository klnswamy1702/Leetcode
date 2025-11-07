# Last updated: 07/11/2025, 13:40:31
class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        dp = [0] * 51  # Initialize an array to store the minimum extra characters.
        n = len(s)

        for i in range(n - 1, -1, -1):
            dp[i] = 1 + dp[i + 1]  # Initialize with one extra character.

            for w in dictionary:
                if i + len(w) <= n and s[i:i + len(w)] == w:
                    dp[i] = min(dp[i], dp[i + len(w)])  # Update if a word in the dictionary is found.

        return dp[0] 
        