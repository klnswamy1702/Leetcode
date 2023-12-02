class Solution(object):
    def twoSum(self, numbers, target):
        f, l = 0, len(numbers)-1
        while numbers[f]+numbers[l] != target:
            if numbers[f]+numbers[l] > target:
                l -= 1
            else:
                f +=1
        return [f+1,l+1]
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        