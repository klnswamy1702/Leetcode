# Last updated: 07/11/2025, 13:42:25
# class Solution:
#     def countOrders(self, n: int) -> int:



from functools import reduce
from operator import mul
class Solution:
    def countOrders(self, n: int) -> int:
        cap = 10**9 + 7
        pickup_permutation = math.factorial(n) % cap
        delivery_permutation = reduce(mul, range(1, 2*n, 2), 1) % cap
        return pickup_permutation * delivery_permutation % cap