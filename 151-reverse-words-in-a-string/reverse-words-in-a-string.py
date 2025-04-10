class Solution:
    def reverseWords(self, s: str) -> str:
        # Step 1: Use split() to divide the string into words
        words = s.split()
        
        # Step 2: Reverse the list of words
        reversed_words = words[::-1]
        
        # Step 3: Join the words back into a string with a single space
        return ' '.join(reversed_words)
        