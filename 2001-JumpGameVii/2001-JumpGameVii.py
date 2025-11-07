# Last updated: 07/11/2025, 13:41:15
class Solution:
    def canReach(self, s: str, minJ: int, maxJ: int) -> bool:
        dp = [c == '0' for c in s]
        pre = 0
        for i in range(1, len(s)):
            if i >= minJ: pre += dp[i - minJ]
            if i > maxJ: pre -= dp[i - maxJ - 1]
            dp[i] &= pre > 0
        return dp[-1]
        