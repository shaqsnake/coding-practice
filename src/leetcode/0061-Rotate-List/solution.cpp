// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-07 11:33:24
 * @LastEditTime: 2019-08-07 11:37:21
 * @Description: 61. Rotate List
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head)
            return head;

        int size = 0;
        for (auto p = head; p; p = p->next)
            size++;
        k %= size;
        if (!k)
            return head;

        auto first = head, second = head;
        while (k--)
            first = first->next;
        while (first->next) {
            first = first->next;
            second = second->next;
        }

        first->next = head;
        head = second->next;
        second->next = NULL;

        return head;
    }
};