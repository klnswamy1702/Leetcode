# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
    #     if not subRoot:
    #         return True
    #     if not root:
    #         return False
    #     if self.sameTree(subRoot, root):
    #         return True
    #     return self.isSubtree(root, subRoot.left) or self.isSubtree(root, subRoot.right)


    # def sameTree(self, s, t):
    #     if not s or not t:
    #         return True
    #     if s and t and s.val == t.val:
    #         return self.sameTree(s.left, t.left) and self.sameTree(s.right, t.right)
    #     return False
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not t:
            return True
        if not s:
            return False

        if self.sameTree(s, t):
            return True
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def sameTree(self, s, t):
        if not s and not t:
            return True
        if s and t and s.val == t.val:
            return self.sameTree(s.left, t.left) and self.sameTree(s.right, t.right)
        return False