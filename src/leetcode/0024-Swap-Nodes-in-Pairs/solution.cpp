// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-07 14:16:47
 * @LastEditTime: 2019-08-07 14:20:31
 * @Description: 24. Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        auto p = dummy;
        while (p->next && p->next->next) {
            auto a = p->next, b = p->next->next;
            a->next = b->next;
            b->next = a;
            p->next = b;
            p = a;
        }

        return dummy->next;
    }
};
