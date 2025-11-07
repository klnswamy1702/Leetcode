# Last updated: 07/11/2025, 13:40:36
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        a, b = max(dimensions, key=lambda x: (x[0]**2 + x[1]**2, x[0] * x[1]))
        return a * b
        