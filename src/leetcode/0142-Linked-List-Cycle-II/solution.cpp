// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-08 09:46:50
 * @LastEditTime: 2019-08-08 10:00:54
 * @Description: 142. Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        auto walker = head, runner = head;

        while (runner) {
            walker = walker->next;
            runner = runner->next;
            if (runner) runner = runner->next;
            else break;

            if (runner == walker) {
                runner = head;
                while (runner != walker) {
                    runner = runner->next;
                    walker = walker->next;
                }

                return runner;
            }
        }

        return nullptr;
    }
};
