// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-06 15:30:02
 * @LastEditTime: 2019-08-06 15:32:53
 * @Description: 287. Find the Duplicate Number
 */
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;

            int cnt = 0;
            for (auto x : nums)
                cnt += l <= x && x <= mid;

            if (cnt > mid - l + 1)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};