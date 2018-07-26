# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root is None:
            return []
        
        res = []
        if root.left is None and root.right is None:
            res.append(str(root.val))
            
        for node in self.binaryTreePaths(root.left):
            res.append(str(root.val) + '->' + node)
        
        for node in self.binaryTreePaths(root.right):
            res.append(str(root.val) + '->' + node)
            
        return res