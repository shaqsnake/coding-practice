// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-26 16:15:41
 * @LastEditTime: 2019-08-26 16:18:34
 * @Description: 560. Subarray Sum Equals K
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;

        int sum = 0, res = 0;
        for (const auto &n : nums) {
            sum += n;
            res += m[sum - k];
            m[sum]++;
        }

        return res;
    }
};
