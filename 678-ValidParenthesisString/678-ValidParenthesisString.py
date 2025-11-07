# Last updated: 07/11/2025, 13:44:09
class Solution:
    def checkValidString(self, s: str) -> bool:
        # cmin = cmax = 0
        # for i in s:
        #     if i == '(':
        #         cmax += 1
        #         cmin += 1
        #     if i == ')':
        #         cmax -= 1
        #         cmin = max(cmin - 1, 0)
        #     if i == '*':
        #         cmax += 1
        #         cmin = max(cmin - 1, 0)
        #     if cmax < 0:
        #         return False
        # return cmin == 0
        cmin = cmax = 0
        for i in s:
            cmax = cmax - 1 if i == ")" else cmax + 1
            cmin = cmin + 1 if i == '(' else max(cmin - 1, 0)
            if cmax < 0: return False
        return cmin == 0
        