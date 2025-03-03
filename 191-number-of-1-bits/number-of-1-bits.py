class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            # If the last bit is 1, increment the count
            count += n & 1
            # Shift bits of n right by 1
            n >>= 1
        return count
        