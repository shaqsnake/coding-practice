// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-08 16:15:32
 * @LastEditTime: 2019-08-08 16:24:41
 * @Description: 101. Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        stack<TreeNode*> sl, sr;
        auto l = root->left, r = root->right;
        while (l || r || sl.size() || sr.size()) {
            while (l && r) {
                sl.push(l), sr.push(r);
                l = l->left, r = r->right;
            }

            if (l || r) return false;

            l = sl.top(), sl.pop();
            r = sr.top(), sr.pop();
            if (l->val != r->val) return false;

            l = l->right, r = r->left;
        }

        return true;
    }

    bool isSymmetric2(TreeNode* root) {
        if (!root) return true;
        return isEqual(root->left, root->right);
    }

private:
    bool isEqual(TreeNode *l, TreeNode *r) {
        if (!l || !r) return !l && !r;
        return l->val == r->val && isEqual(l->left, r->right) && isEqual(l->right, r->left);
    }
};