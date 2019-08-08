// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-08 10:56:14
 * @LastEditTime: 2019-08-08 11:08:22
 * @Description: 148. Sort List
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
    ListNode* sortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        int n = 0;
        for (auto p = head; p; p = p->next) ++n;

        for (int i = 1; i < n; i += i) {
            auto cur = dummy;
            for (int j = 0; j + i < n; j += 2 * i) {
                auto left = cur->next, right = cur->next;
                for (int k = 0; k < i; k++) right = right->next;

                int l = 0, r = 0;
                while (l < i && r < i && right) {
                    if (left->val <= right->val) {
                        cur->next = left;
                        cur = cur->next;
                        left = left->next;
                        l++;
                    } else {
                        cur->next = right;
                        cur = cur->next;
                        right = right->next;
                        r++;
                    }
                }

                while (l < i) {
                    cur->next = left;
                    cur = cur->next;
                    left = left->next;
                    l++;
                }

                while (r < i && right) {
                    cur->next = right;
                    cur = cur->next;
                    right = right->next;
                    r++;
                }

                cur->next = right;
            }
        }

        return dummy->next;
    }
};
