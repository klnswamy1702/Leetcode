# class Solution:
#     def longestCommonPrefix(self, strs: List[str]) -> str:
#         if not strs:
#             return ""
    
#         # Start with the full first string as a prefix
#         prefix = strs[0]
        
#         # Compare the prefix with each string one by one
#         for s in strs[1:]:
#             # Reduce the prefix size until it matches the beginning of `s`
#             while not s.startswith(prefix):
#                 prefix = prefix[:-1]  # Remove the last character from the prefix
#                 if not prefix:  # If prefix becomes empty, no common prefix
#                     return ""
        
#         return prefix

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
    
        # Check each column in each row
        for i in range(len(strs[0])):
            char = strs[0][i]
            
            for s in strs[1:]:
                # If the current string length is less than i or characters mismatch
                if i >= len(s) or s[i] != char:
                    return strs[0][:i]
        
        return strs[0]



        