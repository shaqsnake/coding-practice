// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-26 14:40:50
 * @LastEditTime: 2019-08-26 15:02:29
 * @Description: 652. Find Duplicate Subtrees
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
    int cnt = 0;
    unordered_map<string, int> dict;
    unordered_map<int, int> count;
    vector<TreeNode*> res;

    string dfs(TreeNode *node) {
        if (!node) return to_string(dict["#"]);

        auto left = dfs(node->left);
        auto right = dfs(node->right);
        string tree = to_string(node->val) + left + right;
        
        if(!dict.count(tree)) dict[tree] = cnt++;
        int h = dict[tree];
        count[h]++;
        if (count[h] == 2) res.push_back(node);

        return to_string(h);
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dict["#"] = cnt++;    
        dfs(root);
        return res;
    }
};
