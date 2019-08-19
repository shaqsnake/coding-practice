// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-19 14:55:18
 * @LastEditTime: 2019-08-19 15:01:40
 * @Description: 90. Subsets II
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int x) {
        if (x == nums.size()) {
            res.push_back(path);
            return;
        }

        int k = 0;
        while (x + k < nums.size() && nums[x + k] == nums[x]) k++;

        for (int i = 0; i <= k; i++) {
            dfs(nums, x + k);
            path.push_back(nums[x]);
        }

        for (int i = 0; i <= k; i++) path.pop_back();
    }
};
