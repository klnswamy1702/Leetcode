# class Solution:
#     def isPalindrome(self, s: str) -> bool:
#         # Create a list to hold only alphanumeric characters in lowercase form
#         filtered_chars = [char.lower() for char in s if char.isalnum()]
        
#         # Initialize two pointers
#         left, right = 0, len(filtered_chars) - 1
        
#         # Use two pointers to check palindrome
#         while left < right:
#             # Compare characters and move pointers
#             if filtered_chars[left] != filtered_chars[right]:
#                 return False
#             left, right = left + 1, right - 1
        
#         return True
        
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Initialize two pointers
        left, right = 0, len(s) - 1
        
        while left < right:
            # Move left pointer if not alphanumeric
            while left < right and not s[left].isalnum():
                left += 1
            # Move right pointer if not alphanumeric
            while left < right and not s[right].isalnum():
                right -= 1
            
            # Compare characters in a case-insensitive manner
            if s[left].lower() != s[right].lower():
                return False
            
            # Move both pointers towards the center
            left += 1
            right -= 1
            
        return True