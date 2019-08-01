// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-01 17:38:47
 * @LastEditTime: 2019-08-01 17:40:40
 * @Description: 162. Find Peak Element
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid-1] <= nums[mid]) l = mid;
            else r = mid - 1;
        }

        return r;
    }
};