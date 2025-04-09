# class Solution:
#     def isSubsequence(self, s: str, t: str) -> bool:
#         pointer_s, pointer_t = 0, 0
        
#         while pointer_s < len(s) and pointer_t < len(t):
#             # Check if current character in both strings match
#             if s[pointer_s] == t[pointer_t]:
#                 # Move the pointer for string s
#                 pointer_s += 1
#             # Always move the pointer for string t
#             pointer_t += 1
        
#         # If we've traversed all of s, it's a subsequence of t
#         return pointer_s == len(s)

from bisect import bisect_left
from collections import defaultdict

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # Preprocess t: map each char in t to the list of indices it appears at
        char_indices = defaultdict(list)
        for index, char in enumerate(t):
            char_indices[char].append(index)
        
        # Previous character index in t
        prev_index = -1
        for char in s:
            # Get the list of all indices for the current character
            indices = char_indices[char]
            # Find the least index which is greater than prev_index
            # Equivalent to getting the next occurrence of char in t
            position = bisect_left(indices, prev_index + 1)
            if position == len(indices):
                # If we cannot find a valid subsequence index, return False
                return False
            
            # Update prev_index to the current valid index found
            prev_index = indices[position]
        
        return True
        