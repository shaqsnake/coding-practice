// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-09 09:35:39
 * @LastEditTime: 2019-08-09 09:57:56
 * @Description: 105. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            pos[inorder[i]] = i;

        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    unordered_map<int, int> pos;
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) return nullptr;

        TreeNode *root = new TreeNode(preorder[pl]);
        int k = pos[preorder[pl]] - il;
        root->left = build(preorder, inorder, pl + 1, pl + k, il, il + k - 1);
        root->right = build(preorder, inorder, pl + k + 1, pr, il + k + 1, ir);

        return root;
    }
};