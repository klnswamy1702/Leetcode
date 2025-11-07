# Last updated: 07/11/2025, 13:42:30
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        visited = set()

        def dfs(position):
            if position < 0 or position >= n or position in visited:
                return False
            
            if arr[position] == 0:
                return True

            visited.add(position)
            return dfs(position + arr[position]) or dfs(position - arr[position])

        return dfs(start)
        