class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        j = 0  # Initialize the 'unique' end at the first index
        
        for i in range(1, len(nums)):  # Start checking from the second element
            if nums[i] != nums[j]:  # If a unique element is found
                j += 1  # Move the unique index up
                nums[j] = nums[i]  # Set the unique element at index j
                
        return j + 1  # Return the number of unique elements
        