class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 3:
            return n
        n1, n2 = 2, 3

        for i in range(4, n + 1):
            temp = n1 + n2
            n1 = n2
            n2 = temp
        return n2
        # return int(round(1/5**0.5 * (((1+5**0.5)/2.0)**(n+1) - ((1-5**0.5)/2.0)**(n+1))))