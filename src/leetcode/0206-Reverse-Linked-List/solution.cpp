// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-07 15:06:59
 * @LastEditTime: 2019-08-07 15:10:33
 * @Description: 206. Reverse Linked List
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
    ListNode *reverseList(ListNode *head) {
        if (!head)
            return head;
        ListNode *prev = nullptr;
        auto curr = head;

        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }

        return prev;
    }

    ListNode *reverseList2(ListNode *head) {
        if (!head)
            return head;

        auto a = head, b = head->next;
        while (b) {
            a->next = b->next;
            b->next = head;
            head = b;
            b = a->next;
        }

        return head;
    }
};