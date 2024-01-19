class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()

        i, j, n = 0, 0, len(nums)
        ans = [0]*n

        while i < n and j < n:
            ans[i] = nums[j]
            i = i + 2
            j = j + 1

        i = 1
        while i < n and j < n:
            ans[i] = nums[j]
            i = i + 2
            j = j + 1

        return ans
        