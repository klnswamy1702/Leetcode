# class Solution:
#     def convert(self, s: str, numRows: int) -> str:
#         # Edge case: If only one row, return the string itself.
#         if numRows == 1 or numRows >= len(s):
#             return s

#         # List of strings, each represents a row in the zigzag pattern.
#         rows = [''] * numRows
#         current_row, step = 0, 1

#         # Loop through each character in the string
#         for char in s:
#             # Add the character to the current row
#             rows[current_row] += char
            
#             # Decide whether we need to move up or down
#             if current_row == 0:
#                 step = 1
#             elif current_row == numRows - 1:
#                 step = -1
            
#             # Move to the next row
#             current_row += step

#         # Concatenate all rows to get the final converted string
#         return ''.join(rows)


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # Edge case: If only one row, return the string itself.
        if numRows == 1 or numRows >= len(s):
            return s

        # String to hold the final result
        result = []
        cycle_len = 2 * numRows - 2

        # Handle each row
        for i in range(numRows):
            # Traverse through the given string to get characters belonging to this row
            for j in range(i, len(s), cycle_len):
                # Add the primary character in each cycle
                result.append(s[j])
                
                # If it's not the first or last row, add the diagonal character
                if i != 0 and i != numRows - 1 and j + cycle_len - 2 * i < len(s):
                    result.append(s[j + cycle_len - 2 * i])

        # Join all parts to form the final result string
        return ''.join(result)
