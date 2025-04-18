class Solution:
    def searchMatrix(self, mat: List[List[int]], target: int) -> bool:
        # m=len(matrix)
        # n=len(matrix[0])
        
        # i=m-1
        # j=0
        
        # while i>=0 and j<n:
        #     if matrix[i][j]==target:
        #         return True
        #     elif matrix[i][j]<target:
        #         j+=1
        #     else:
        #         i-=1
        # return False

        m=len(mat)
        n=len(mat[0])
        
        for i in range(m):
            if mat[i][0]<=target and mat[i][-1]>=target:
                lo=0
                hi=n
                while (lo<hi):
                    mid=(lo+hi)//2
                    
                    if mat[i][mid]==target:
                        return True
                    elif mat[i][mid]<target:
                        lo = mid + 1
                    else:
                        hi = mid
                        
        return False
        