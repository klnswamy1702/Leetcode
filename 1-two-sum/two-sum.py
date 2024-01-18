class Solution(object):
    def twoSum(self, nums, target):
        numMap = {}
        n = len(nums)

        for i in range(n):
            complement = target - nums[i]
            if complement in numMap:
                return [numMap[complement], i]
            numMap[nums[i]] = i

        return []
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        