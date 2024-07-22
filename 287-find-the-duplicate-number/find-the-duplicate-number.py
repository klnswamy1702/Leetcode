# class Solution:
#     def findDuplicate(self, nums: List[int]) -> int:
#         seen = set()
#         for num in nums:
#             if num in seen:
#                 return num
#             seen.add(num)


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        cnt = [0] * (len(nums) + 1)
        for num in nums:
            cnt[num] += 1
            if cnt[num] > 1:
                return num
        return len(nums)