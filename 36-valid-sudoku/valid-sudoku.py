class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        seen = set()  # A set to track the unique composite keys

        # Iterate through each cell of the board
        for r in range(9):
            for c in range(9):
                num = board[r][c]
                if num == '.':
                    continue  # Ignore empty cells

                # Create composite keys for current row, column, and box
                row_key = f"row-{r}-{num}"
                col_key = f"col-{c}-{num}"
                box_key = f"box-{(r // 3) * 3 + (c // 3)}-{num}"

                # Check if any key is already in the seen set
                if row_key in seen or col_key in seen or box_key in seen:
                    return False

                # Add the composite keys to the set
                seen.add(row_key)
                seen.add(col_key)
                seen.add(box_key)

        return True
        