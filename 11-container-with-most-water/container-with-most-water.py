# class Solution:
#     def maxArea(self, height: List[int]) -> int:
#         i, j = 0, len(height) - 1
#         water = 0
#         while i < j:
#             water = max(water, (j - i) * min(height[i], height[j]))
#             if height[i] < height[j]:
#                 i += 1
#             else:
#                 j -= 1
#         return water 

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        res = 0

        while l < r:
            res = max(res, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            elif height[r] <= height[l]:
                r -= 1
            
        return res