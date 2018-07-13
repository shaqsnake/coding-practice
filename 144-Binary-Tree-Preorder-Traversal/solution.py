# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = list() # store the results
        stack = list() # store the op in order
        stack.append(Frame('v', root))
        
        # search the stack
        while len(stack) > 0:
            frame = stack.pop()
            if not frame.node:
                continue
            # print the node value
            if frame.op == 'p':
                res.append(frame.node.val)
            # travel the node in order
            else:
                stack.append(Frame('v', frame.node.right))
                stack.append(Frame('v', frame.node.left))
                stack.append(Frame('p', frame.node))
        
        return res
    

class Frame(object):
    def __init__(self, op, node):
        self.op = op
        self.node = node