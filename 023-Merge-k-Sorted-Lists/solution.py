from Queue import PriorityQueue

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        cur = dummy = ListNode(-1)
        
        pq = PriorityQueue()
        for node in lists:
            pq.put((node.val, node))
            
        while pq.qsize():
            cur.next = pq.get()[1]
            cur = cur.next
            if cur.next:
                pq.put((cur.next.val, cur.next))
                
        return dummy.next
        