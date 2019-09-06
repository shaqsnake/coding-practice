// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-04 16:32:58
 * @LastEditTime: 2019-09-06 15:21:12
 * @Description: 53. Maximum Subarray
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;
        for (const auto &n : nums) {
            sum = max(sum + n, n);
            res = max(res, sum);
        }

        return res;
    }

    int maxSubArray2(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n+1);
        
        for (int i = 1; i <= n; i++) {
           f[i] = max(f[i - 1], 0) + nums[i-1];
        }
        
        int res = INT_MIN;
        for (int i = 1; i <= n; i++) {
            res = max(res, f[i]);
        }
        
        return res;
    }
};
