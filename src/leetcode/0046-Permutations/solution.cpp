// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-16 14:06:24
 * @LastEditTime: 2019-08-16 14:14:37
 * @Description: 46. Permutations
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permute(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) st.push_back(false);
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int x) {
        if (x == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (!st[i]) {
                path.push_back(nums[i]);
                st[i] = true;
                dfs(nums, x + 1);
                st[i] = false;
                path.pop_back();
            }
        }
    }
};
