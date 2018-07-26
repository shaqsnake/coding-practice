# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if root is None:
            return 0
        
        return self.findPath(root, sum) + self.pathSum(root.left, sum) + self.pathSum(root.right, sum)
        
    def findPath(self, node, sum):
        
        if node is None:
            return 0
        
        return int(node.val == sum) + self.findPath(node.left, sum-node.val) + self.findPath(node.right, sum-node.val)
        