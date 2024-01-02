class Solution:
    def peopleAwareOfSecret(self, n: int, dd: int, ff: int) -> int:
        dp, mod, ans = [0] * 1001, 1000000007, 0
        dp[1] = 1
        for d in range(1, n + 1):
            if dp[d] > 0:
                for nxt in range(d + dd, min(d + ff, 1001)):
                    dp[nxt] += dp[d]
        for d in range(1, n + 1):
            if d + ff > n:
                ans += dp[d]
        return ans % mod
        