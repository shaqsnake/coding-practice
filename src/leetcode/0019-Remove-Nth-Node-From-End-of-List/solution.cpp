// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-06 16:39:48
 * @LastEditTime: 2019-08-06 16:43:36
 * @Description: 19. Remove Nth Node From End of List
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        auto first = dummy, second = dummy;
        while (n--)
            first = first->next;

        while (first->next) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;

        return dummy->next;
    }
};
