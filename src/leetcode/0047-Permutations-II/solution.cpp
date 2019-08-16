// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-16 17:02:56
 * @LastEditTime: 2019-08-16 17:15:56
 * @Description: 47. Permutations II
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;
    int n;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        path = vector<int>(n);
        st = vector<bool>(n);
        
        sort(nums.begin(), nums.end());

        dfs(nums, 0, 0);

        return res;    
    }

    void dfs(vector<int> &nums, int u, int start) {
        if (u == n) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < n; i++) {
            if (!st[i]) {
                st[i] = true;
                path[i] = nums[u];
                dfs(nums, u + 1, u + 1 < n && nums[u] == nums[u+1] ? i + 1 : 0);
                st[i] = false;
            }
        }
    }
};
