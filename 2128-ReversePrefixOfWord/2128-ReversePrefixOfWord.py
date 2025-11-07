# Last updated: 07/11/2025, 13:41:03
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        # i = word.find(ch)
        # return word if i == -1 else word[i::-1] + word[i + 1 :]
        i = word.find(ch) + 1
        return word[:i][::-1] + word[i:]
        