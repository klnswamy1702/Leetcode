# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None

        mid = len(nums) // 2

        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid+1:])

        return root
        # def helper(left, right):
        #     if left > right:
        #         return None

        #     # always choose left middle node as a root
        #     p = (left + right) // 2

        #     # preorder traversal: node -> left -> right
        #     root = TreeNode(nums[p])
        #     root.left = helper(left, p - 1)
        #     root.right = helper(p + 1, right)
        #     return root

        # return helper(0, len(nums) - 1)
