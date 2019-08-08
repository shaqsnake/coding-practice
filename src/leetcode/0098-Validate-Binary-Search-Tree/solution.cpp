// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-08 14:13:13
 * @LastEditTime: 2019-08-08 14:17:55
 * @Description: 98. Validate Binary Search Tree
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }

private:
    bool isValid(TreeNode *node, long long min, long long max) {
        if (!node) return true;

        if (node->val < min || node->val > max) return false;

        return isValid(node->left, min, node->val - 1ll) && isValid(node->right, node->val + 1ll, max);
    }
};