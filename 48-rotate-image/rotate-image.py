class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # n = len(matrix)
    
        # # Step 1: Transpose the matrix.
        # for i in range(n):
        #     for j in range(i, n):
        #         # Swap elements to transpose the matrix
        #         matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # # Step 2: Reverse each row.
        # for i in range(n):
        #     # Reverse this row
        #     matrix[i].reverse()

        n = len(matrix)
    
        # Rotate layer by layer
        for layer in range(n // 2):
            first = layer
            last = n - 1 - layer
            for i in range(first, last):
                offset = i - first
                
                # Save the top element
                top = matrix[first][i]
                
                # Left -> Top
                matrix[first][i] = matrix[last - offset][first]
                
                # Bottom -> Left
                matrix[last - offset][first] = matrix[last][last - offset]
                
                # Right -> Bottom
                matrix[last][last - offset] = matrix[i][last]
                
                # Top -> Right
                matrix[i][last] = top
        