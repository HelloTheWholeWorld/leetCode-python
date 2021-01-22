# Definition for a binary tree node.
from typing import List
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 第一种，递归类型
# class Solution:
#     def postorderTraversal(self, root: TreeNode) -> List[int]:
#         if not root:
#             return []
#         res = []
#         def help(node):
#             if node.left:
#                 help(node.left)
#             if node.right:
#                 help(node.right)
#             res.append(node.val)
#         help(root)
#         return res

# 第二种，迭代类型
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        stack = []
        res = []
        stack.append(root)
        while stack:
            node = stack.pop()
            if node:
                res = [node.val] + res
                stack.append(node.left)
                stack.append(node.right)
        return res
if __name__ == '__main__':
    node = TreeNode(1)
    node.right = TreeNode(2)
    node.right.left = TreeNode(3)
    print(Solution().postorderTraversal(node))