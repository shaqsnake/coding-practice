// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-07 16:36:15
 * @LastEditTime: 2019-08-07 16:41:31
 * @Description: 160. Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;

        while (a != b) {
            if (a) a = a->next;
            else a = headB;
            if (b) b = b->next;
            else b = headA;
        }

        return a;
    }
};