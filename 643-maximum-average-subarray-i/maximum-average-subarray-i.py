class Solution:
    # def findMaxAverage(self, nums: List[int], k: int) -> float:
    def findMaxAverage(self, A: List[int], K: int) -> float:
        su = 0
        ma = float('-inf')
        for i, x in enumerate(A):
            su += x
            if i >= K:
                su -= A[i-K]
            if i >= K - 1:
                ma = max(ma, su)
        return ma / float(K)
        