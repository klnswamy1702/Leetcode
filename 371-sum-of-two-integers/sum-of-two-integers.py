class Solution:
    def getSum(self, a: int, b: int) -> int:
        # 32 bits integer max
        MAX = 0x7FFFFFFF
        # Mask for bits beyond 32
        MASK = 0xFFFFFFFF
        # Iterating until there are no carries
        while b != 0:
            # Carry is AND, shifted left by 1
            carry = (a & b) << 1
            # Add without carry using XOR
            a = (a ^ b) & MASK
            # Apply mask to carry
            b = carry & MASK
        # If a is negative, use ~ operation with MASK
        return a if a <= MAX else ~(a ^ MASK)
        