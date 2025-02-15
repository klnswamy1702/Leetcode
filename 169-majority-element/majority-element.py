class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # count = 0
        # candidate = 0
        
        # for num in nums:
        #     if count == 0:
        #         candidate = num
            
        #     if num == candidate:
        #         count += 1
        #     else:
        #         count -= 1
        
        # return candidate
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate
        