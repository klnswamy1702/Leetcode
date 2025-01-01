# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # if root is None:
        #     return 0
        # else:
        #     left_height = self.maxDepth(root.left)
        #     right_height = self.maxDepth(root.right)
        #     return max(left_height, right_height) + 1
        # stack = []
        # if root is not None:
        #     stack.append((1, root))

        # depth = 0
        # while stack != []:
        #     current_depth, root = stack.pop()
        #     if root is not None:
        #         depth = max(depth, current_depth)
        #         stack.append((current_depth + 1, root.left))
        #         stack.append((current_depth + 1, root.right))

        # return depth
        depth = 0
        level = [root] if root else []
        while level:
            depth += 1
            queue = []
            for el in level:
                if el.left:
                    queue.append(el.left)
                if el.right:
                    queue.append(el.right)
            level = queue
            
        return depth