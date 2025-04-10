# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:
# import random
# class Solution:
#     def findSecretWord(self, words: List[str], master: 'Master') -> None:
            
# from collections import defaultdict
# import random

# class Solution:
#     def findSecretWord(self, words: List[str], master: 'Master') -> None:
#         def match_count(w1: str, w2: str) -> int:
#             return sum(c1 == c2 for c1, c2 in zip(w1, w2))

#         possible_words = words[:]
        
#         for _ in range(10):  # Up to 10 allowed guesses
#             # Frequency table to use minimax strategy
#             count_map = defaultdict(int)
#             for word1 in possible_words:
#                 for word2 in possible_words:
#                     if word1 != word2:
#                         count_map[(word1, match_count(word1, word2))] += 1

#             # Choose the word that minimizes the worst-case size of possible_words after guess
#             best_guess = None
#             min_worst_case = float('inf')
#             for word in possible_words:
#                 groups = defaultdict(int)
#                 for other in possible_words:
#                     if word != other:
#                         groups[match_count(word, other)] += 1
#                 worst_case = max(groups.values(), default=0)
#                 if worst_case < min_worst_case:
#                     min_worst_case = worst_case
#                     best_guess = word

#             if not best_guess:
#                 best_guess = random.choice(possible_words)

#             matches = master.guess(best_guess)
#             if matches == 6:
#                 return  # Guessed correctly

#             # Filter down words that have exactly `matches` letters in common with the guess
#             possible_words = [w for w in possible_words if match_count(best_guess, w) == matches]

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

