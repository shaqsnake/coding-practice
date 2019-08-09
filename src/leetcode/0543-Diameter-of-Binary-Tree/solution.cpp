// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-06-10 17:41:50
 * @LastEditTime: 2019-08-09 14:05:54
 * @Description: 543. Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode *root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    int diameterOfBinaryTree2(TreeNode *root) {
        int res = 0;
        dfs2(root, res);
        return res;
    }

private:
    int dfs(TreeNode *node, int &res) {
        if (!node) return 0;
        int left = dfs(node->left, res);
        int right = dfs(node->right, res);
        
        res = max(res, left + right);

        return max(left, right) + 1;
    }

    int dfs2(TreeNode *node, int &res) {
        if (!node)
            return 0;
        int ldepth = 0, rdepth = 0;
        if (node->left)
            ldepth = dfs(node->left, res) + 1;
        if (node->right)
            rdepth = dfs(node->right, res) + 1;
        res = max(res, ldepth + rdepth);
        return max(ldepth, rdepth);
    }
};
