// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-12 16:47:07
 * @LastEditTime: 2019-09-12 17:03:26
 * @Description: 198. House Robber
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1), g(n + 1);

        for (int i = 1; i <= n; i++) {
            f[i] = max(f[i - 1], g[i - 1]);
            g[i] = f[i - 1] + nums[i - 1];
        }

        return max(f[n], g[n]);
    }
};
