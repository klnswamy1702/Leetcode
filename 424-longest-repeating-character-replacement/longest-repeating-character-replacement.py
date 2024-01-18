class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        
        l = 0
        maxxxx = 0
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)
            maxxxx = max(maxxxx, count[s[r]])

            if (r - l + 1) - maxxxx > k:
                count[s[l]] -= 1
                l += 1

        return (r - l + 1)
        