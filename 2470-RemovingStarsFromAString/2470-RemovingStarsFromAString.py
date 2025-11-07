# Last updated: 07/11/2025, 13:40:42
class Solution:
    def removeStars(self, s: str) -> str:
        res = []
        for c in s :
            if res and c == '*':
                res.pop()
            else:
                res.append(c)
        return ''.join(res)