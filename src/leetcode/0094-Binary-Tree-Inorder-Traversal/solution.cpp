// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-08 15:01:05
 * @LastEditTime: 2019-08-08 15:30:53
 * @Description: 94. Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        if (root->left) {
            auto left = inorderTraversal(root->left);
            res.insert(res.end(), left.begin(), left.end());
        }
        res.push_back(root->val);
        if (root->right) {
            auto right = inorderTraversal(root->right);
            res.insert(res.end(), right.begin(), right.end());
        }

        return res;
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;

        auto p = root;
        while (p || s.size()) {
            while (p) {
                s.push(p);
                p = p->left;
            }

            p = s.top();
            s.pop();
            res.push_back(p->val);

            p = p->right;
        }

        return res;
    }
};