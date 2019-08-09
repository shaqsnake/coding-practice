// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-09 15:43:15
 * @LastEditTime: 2019-08-09 16:00:01
 * @Description: 297. Serialize and Deserialize Binary Tree
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        encode(root, res);
        return res;
    }

    void encode(TreeNode *node, string &res) {
        if (!node) res += "#,";
        else {
            res += to_string(node->val) + ",";
            encode(node->left, res);
            encode(node->right, res);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return decode(data, pos);
    }

    TreeNode *decode(const string &data, int &pos) {
        if (data[pos] == '#') {
            pos += 2;
            return nullptr;
        }

        bool isMinus = false;
        int d = 0;
        while (data[pos] != ',') {
            if (data[pos] == '-') isMinus = true;
            else d = d * 10 + data[pos] - '0';
            pos++;
        }
        pos++;
        
        if (isMinus) d *= -1;

        TreeNode *node = new TreeNode(d);
        node->left = decode(data, pos);
        node->right = decode(data, pos);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
