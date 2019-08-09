// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-09 14:36:23
 * @LastEditTime: 2019-08-09 14:39:42
 * @Description: 124. Binary Tree Maximum Path Sum
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
    int res = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode *node) {
        if (!node) return 0;

        int l = max(0, dfs(node->left));
        int r = max(0, dfs(node->right));

        res = max(res, l + r + node->val);

        return max(node->val + l, node->val + r);
    }
};