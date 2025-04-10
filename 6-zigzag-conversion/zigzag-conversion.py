class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # Edge case: If only one row, return the string itself.
        if numRows == 1 or numRows >= len(s):
            return s

        # List of strings, each represents a row in the zigzag pattern.
        rows = [''] * numRows
        current_row, step = 0, 1

        # Loop through each character in the string
        for char in s:
            # Add the character to the current row
            rows[current_row] += char
            
            # Decide whether we need to move up or down
            if current_row == 0:
                step = 1
            elif current_row == numRows - 1:
                step = -1
            
            # Move to the next row
            current_row += step

        # Concatenate all rows to get the final converted string
        return ''.join(rows)
        