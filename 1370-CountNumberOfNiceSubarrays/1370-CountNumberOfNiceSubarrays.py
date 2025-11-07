# Last updated: 07/11/2025, 13:42:47
class Solution:
    def numberOfSubarrays(self, A: List[int], k: int) -> int:
        def atMost(k):
            res = i = 0
            for j in range(len(A)):
                k -= A[j] % 2
                while k < 0:
                    k += A[i] % 2
                    i += 1
                res += j - i + 1
            return res

        return atMost(k) - atMost(k - 1)