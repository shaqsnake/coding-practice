// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-07 11:02:24
 * @LastEditTime: 2019-08-07 11:04:54
 * @Description: 83. Remove Duplicates from Sorted List
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
    ListNode *deleteDuplicates(ListNode *head) {
        auto cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val)
                *cur = *(cur->next);
            else
                cur = cur->next;
        }

        return head;
    }
};
