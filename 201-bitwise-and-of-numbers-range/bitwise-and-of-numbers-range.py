class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        # # Start with the initial number
        # result = m
        # # Iterate through the numbers from m to n
        # for num in range(m+1, n+1):
        #     result &= num
        #     # Early stop if result becomes zero, because AND with 0 will always be zero
        #     if result == 0:
        #         break
        # return result

        # # Reduce the range by repeatedly zeroing out the least significant bit of n 
        # # until n is less than or equal to m.
        # while m < n:
        #     # Remove the least significant 1-bit from n
        #     n = n & (n - 1)
        # return n

        # Initialize a counter for shifted bits
        shift = 0
        # Shift both numbers right until they are the same
        while m < n:
            m >>= 1
            n >>= 1
            shift += 1
        # Shift back to the original positions
        return m << shift
        