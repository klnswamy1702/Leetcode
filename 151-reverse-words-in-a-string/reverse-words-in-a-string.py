# class Solution:
#     def reverseWords(self, s: str) -> str:
#         # Step 1: Use split() to divide the string into words
#         words = s.split()
        
#         # Step 2: Reverse the list of words
#         reversed_words = words[::-1]
        
#         # Step 3: Join the words back into a string with a single space
#         return ' '.join(reversed_words)

class Solution:
    def reverseWords(self, s: str) -> str:
        # Helper function to reverse a portion of the list
        def reverse_list(chars, start, end):
            while start < end:
                chars[start], chars[end] = chars[end], chars[start]
                start, end = start + 1, end - 1

        # Step 1: Trim the input string (Python's split does it for us)
        char_list = list(s.strip())

        # Step 2-3: Reverse the entire list
        reverse_list(char_list, 0, len(char_list) - 1)

        # Step 4: Reverse each word in the reversed list
        n = len(char_list)
        start = 0
        while start < n:
            while start < n and char_list[start] == ' ':
                start += 1
            end = start
            while end < n and char_list[end] != ' ':
                end += 1
            reverse_list(char_list, start, end - 1)
            start = end

        # Step 5: Join the characters back to a string, removing redundant spaces
        return ' '.join(''.join(char_list).split())
        