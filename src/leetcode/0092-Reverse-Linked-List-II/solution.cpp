// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-07 16:09:25
 * @LastEditTime: 2019-08-07 16:14:27
 * @Description: 92. Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        auto h = dummy, t = dummy;
        for (int i = 0; i < m-1; i++) h = h->next;
        for (int i = 0; i < n+1; i++) t = t->next;

        auto a = h->next, b = h->next->next;
        while (b != t) {
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }

        h->next->next = t;
        h->next = a;

        return dummy->next;
    }
};
