# Last updated: 07/11/2025, 13:43:43
# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:
            

from collections import Counter

class Solution:
    def findSecretWord(self, words: List[str], master: 'Master') -> None:
        def match_count(w1, w2):
            return sum(c1 == c2 for c1, c2 in zip(w1, w2))

        for _ in range(30):  # Up to allowedGuesses
            # Step 1: Count frequency of each letter at each position
            freq = [Counter(w[i] for w in words) for i in range(6)]

            # Step 2: Score each word based on common letters
            def score(word):
                return sum(freq[i][c] for i, c in enumerate(word))

            guess = max(words, key=score)
            matches = master.guess(guess)
            if matches == 6:
                return  # Guessed correctly

            # Step 3: Filter words matching same match count
            words = [w for w in words if match_count(w, guess) == matches]

# class Solution:
#   def findSecretWord(self, words: list[str], master: 'Master') -> None:
#     for _ in range(10):
#       guessedWord = words[random.randint(0, len(words) - 1)]
#       matches = master.guess(guessedWord)
#       if matches == 6:
#         break
#       words = [
#           word for word in words
#           if sum(c1 == c2 for c1, c2 in zip(guessedWord, word)) == matches]

