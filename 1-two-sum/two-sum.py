class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # hashmap = {}
        # for i in range(len(nums)):
        #     complement = target - nums[i]
        #     if complement in hashmap:
        #         return [i, hashmap[complement]]
        #     hashmap[nums[i]] = i
        # # Return an empty list if no solution is found
        # return []
        numToIndex = {}

        for i, num in enumerate(nums):
            if target - num in numToIndex:
                return numToIndex[target - num], i
            numToIndex[num] = i
        