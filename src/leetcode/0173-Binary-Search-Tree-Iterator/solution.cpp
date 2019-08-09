// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-09 15:14:56
 * @LastEditTime: 2019-08-09 15:19:17
 * @Description: 173. Binary Search Tree Iterator
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
class BSTIterator {
public:
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }    
    }
    
    /** @return the next smallest number */
    int next() {
        auto node = s.top();
        s.pop();
        int res = node->val;

        node = node->right;
        while (node) {
            s.push(node);
            node = node->left;
        }

        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
