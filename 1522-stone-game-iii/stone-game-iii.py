# class Solution:
#     def stoneGameIII(self, stoneValue: List[int]) -> str:
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        # Step 1: Compute prefix sums
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stoneValue[i]
        
        # Step 2: Initialize DP array
        dp = [0] * (n + 1)  # dp[n] = 0 by default
        
        # Step 3: Fill DP array from right to left
        for i in range(n - 1, -1, -1):
            max_diff = float('-inf')  # Use negative infinity to handle all cases
            # Try taking 1, 2, or 3 stones, limited by remaining stones
            for k in range(1, min(3, n - i) + 1):
                # Current player's gain minus opponent's optimal difference
                current_diff = (prefix[i + k] - prefix[i]) - dp[i + k]
                max_diff = max(max_diff, current_diff)
            dp[i] = max_diff
        
        # Step 4: Determine the winner based on dp[0]
        if dp[0] > 0:
            return "Alice"
        elif dp[0] < 0:
            return "Bob"
        else:
            return "Tie"