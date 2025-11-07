# Last updated: 07/11/2025, 13:43:02
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        if str1 + str2 != str2 + str1:
            return ""
        # If strings are equal than return the substring from 0 to gcd of size(str1), size(str2)
        
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        return str1[:gcd(len(str1), len(str2))]
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        