class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        # ans = []

        # for num in range(1,n+1):

        #     divisible_by_3 = (num % 3 == 0)
        #     divisible_by_5 = (num % 5 == 0)

        #     if divisible_by_3 and divisible_by_5:
        #         # Divides by both 3 and 5, add FizzBuzz
        #         ans.append("FizzBuzz")
        #     elif divisible_by_3:
        #         # Divides by 3, add Fizz
        #         ans.append("Fizz")
        #     elif divisible_by_5:
        #         # Divides by 5, add Buzz
        #         ans.append("Buzz")
        #     else:
        #         # Not divisible by 3 or 5, add the number
        #         ans.append(str(num))

        # return ans

        # ans list
        ans = []

        for num in range(1,n+1):

            divisible_by_3 = (num % 3 == 0)
            divisible_by_5 = (num % 5 == 0)

            num_ans_str = ""

            if divisible_by_3:
                # Divides by 3
                num_ans_str += "Fizz"
            if divisible_by_5:
                # Divides by 5
                num_ans_str += "Buzz"
            if not num_ans_str:
                # Not divisible by 3 or 5
                num_ans_str = str(num)

            # Append the current answer str to the ans list
            ans.append(num_ans_str)  

        return ans
        