# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return TreeNode(val)
        if val < root.val:
            if not root.left:
                root.left = TreeNode(val)
            else:
                self.insertIntoBST(root.left, val)
        else:
            if not root.right:
                root.right = TreeNode(val)
            else:
                self.insertIntoBST(root.right, val)
        return root


if __name__ == "__main__":
    r = TreeNode(4)
    r.left = TreeNode(2)
    r.left.right = TreeNode(3)
    r.left.left = TreeNode(1)
    r.right = TreeNode(7)
    r = Solution().insertIntoBST(r, 5)