class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(row, col):
            # Mark the current cell as '0' to indicate the land is visited
            grid[row][col] = '0'
            # Explore all four directions from the current cell
            for dx, dy in zip(directions[:-1], directions[1:]):
                new_row, new_col = row + dx, col + dy
                # Check if the new cell is within grid bounds and is land ('1')
                if 0 <= new_row < rows and 0 <= new_col < cols and grid[new_row][new_col] == '1':
                    # Perform DFS on the new cell
                    dfs(new_row, new_col)

        # Initialize count of islands
        island_count = 0
        # Define the directions to explore
        directions = (-1, 0, 1, 0, -1)
        # Get the dimensions of the grid
        rows, cols = len(grid), len(grid[0])
        # Iterate over each cell in the grid
        for row in range(rows):
            for col in range(cols):
                # If the cell is land ('1'), it's a new island
                if grid[row][col] == '1':
                    # Perform DFS to mark all connected land for the current island
                    dfs(row, col)
                    # Increment the island count
                    island_count += 1
        # Return the total number of islands
        return island_count
        