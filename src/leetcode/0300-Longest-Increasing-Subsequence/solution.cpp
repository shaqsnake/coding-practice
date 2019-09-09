// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-08 15:20:36
 * @LastEditTime: 2019-09-09 09:54:55
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

    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int> q(n + 1);
        q[0] = INT_MIN;

        int len = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = len;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (q[mid] < nums[i]) l = mid;
                else r = mid - 1;
            }

            len = max(len, r + 1);
            q[r + 1] = nums[i];
        }

        return len;
    }
};
