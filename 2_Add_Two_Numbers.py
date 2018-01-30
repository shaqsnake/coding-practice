"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
"""
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __str__(self):
        res = ''
        while self:
            if res:
                res += '->' + str(self.val)
            else:
                res += str(self.val)
            self = self.next
        return res

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # Define head to outpur, moving cursor to calculate
        head = cursor = ListNode(0)
        # If sum value > 10, accumulate add 1 to next loop
        carry = 0
        while l1 or l2 or carry:
            v1 = v2 = 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            # Use div and mod with 10 to get carry and value
            carry, v = divmod(v1+v2+carry, 10)
            # move to next ListNode and continue counting
            cursor.next = ListNode(v)
            cursor = cursor.next
        return head.next


if __name__ == '__main__':
    # Construct l1, using cursor point
    l1 = p = ListNode(3)
    p.next = ListNode(6)
    p = p.next
    p.next = ListNode(1)
    print(l1)
    # Construct l2
    l2 = p = ListNode(1)
    p.next = ListNode(4)
    p = p.next
    p.next = ListNode(2)
    print(l2)
    # Add two ListNode
    print(Solution().addTwoNumbers(l1, l2))
