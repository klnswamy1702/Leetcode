class Solution:
    def reverseBits(self, n: int) -> int:
        # result = 0
    
        # for i in range(32):
        #     # Extract the least significant bit of n
        #     bit = n & 1
            
        #     # Shift the extracted bit to its correct reversed position
        #     result = (result << 1) | bit
            
        #     # Prepare n for the next iteration by shifting right
        #     n >>= 1
        
        # return result
        
        result = 0
        for _ in range(32):
            # Combine shift and masking operations
            result = (result << 1) | (n & 1)
            n >>= 1  # Move to process next bit
            
        return result