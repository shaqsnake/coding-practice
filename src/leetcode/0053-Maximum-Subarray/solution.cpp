// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-04 16:32:58
 * @LastEditTime: 2019-09-04 16:38:19
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
};
