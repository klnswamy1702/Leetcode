# Last updated: 07/11/2025, 13:40:54
class Solution:
    def digitSum(self, s: str, k: int) -> str:
           return self.digitSum(''.join(str(sum(map(int, n))) for n in itertools.zip_longest(*[iter(s)] * k, fillvalue='0')), k) if len(s) > k else s 