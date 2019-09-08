// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-08 15:20:36
 * @LastEditTime: 2019-09-08 15:57:36
 * @Description: 300. Longest Increasing Subsequence
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            for (int j = 0; j <= i; j++)
                if (nums[i] > nums[j]) f[i] = max(f[i], f[j] + 1);
        }

        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, f[i]);
        return res;
    }
};
