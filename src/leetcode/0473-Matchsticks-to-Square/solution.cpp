// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-20 14:04:39
 * @LastEditTime: 2019-08-20 14:18:27
 * @Description: 473. Matchsticks to Square
 */

class Solution {
public:
    vector<bool> st;

    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for (const auto &n : nums) sum += n;
        if (!sum || sum % 4) return false;

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        st = vector<bool>(nums.size());
        return dfs(nums, 0, 0, sum / 4);
    }

    bool dfs(vector<int> &nums, int x, int cur, int length) {
        if (cur == length) x++, cur = 0;
        if (x == 4) return true;

        for (int i = 0; i < nums.size(); i++) {
            if (!st[i] && cur + nums[i] <= length) {
                st[i] = true;
                if (dfs(nums, x, cur + nums[i], length)) return true;
                st[i] = false;

                if (!cur) return false;
                if (cur + nums[i] == length) return false;
                while (i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
            }
        }

        return false;
    }
};
