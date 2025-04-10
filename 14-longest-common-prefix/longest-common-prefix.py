class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
    
        # Start with the full first string as a prefix
        prefix = strs[0]
        
        # Compare the prefix with each string one by one
        for s in strs[1:]:
            # Reduce the prefix size until it matches the beginning of `s`
            while not s.startswith(prefix):
                prefix = prefix[:-1]  # Remove the last character from the prefix
                if not prefix:  # If prefix becomes empty, no common prefix
                    return ""
        
        return prefix


# class Solution:
#     def longestCommonPrefix(self, strs: List[str]) -> str:
#         if not strs:
#             return ""
    
#         # Check each column in each row
#         for i in range(len(strs[0])):
#             char = strs[0][i]
            
#             for s in strs[1:]:
#                 # If the current string length is less than i or characters mismatch
#                 if i >= len(s) or s[i] != char:
#                     return strs[0][:i]
        
#         return strs[0]

# class Solution:
#     def longestCommonPrefix(self, strs: List[str]) -> str:
#         if not strs:
#             return ""
    
#         def common_prefix(left, right):
#             min_len = min(len(left), len(right))
#             for i in range(min_len):
#                 if left[i] != right[i]:
#                     return left[:i]
#             return left[:min_len]
        
#         def longest_common_prefix_recursive(l, r):
#             if l == r:
#                 return strs[l]
#             else:
#                 # Divide the list into two halves
#                 mid = (l + r) // 2
#                 lcp_left = longest_common_prefix_recursive(l, mid)
#                 lcp_right = longest_common_prefix_recursive(mid + 1, r)
#                 # Conquer/Combine step
#                 return common_prefix(lcp_left, lcp_right)
        
#         return longest_common_prefix_recursive(0, len(strs) - 1)


# class Solution:
#     def longestCommonPrefix(self, strs: List[str]) -> str:
#         if not strs:
#             return ""
#         # Find the minimum length string in strs
#         min_length = min(len(s) for s in strs)
        
#         low, high = 0, min_length
        
#         def is_common_prefix(length):
#             prefix = strs[0][:length]
#             return all(s.startswith(prefix) for s in strs[1:])
        
#         while low <= high:
#             mid = (low + high) // 2
#             if is_common_prefix(mid):
#                 low = mid + 1
#             else:
#                 high = mid - 1
        
#         return strs[0][:(low + high) // 2]


        