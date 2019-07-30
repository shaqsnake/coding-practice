// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-07-30 16:24:23
 * @LastEditTime: 2019-07-30 16:30:23
 * @Description:
 */
class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty())
            return -1;

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] <= nums.back())
                r = mid;
            else
                l = mid + 1;
        }

        if (target <= nums.back())
            r = nums.size() - 1;
        else
            l = 0, r--;

        while (l < r) {
            int mid = l + r >> 1;
            if (target <= nums[mid])
                r = mid;
            else
                l = mid + 1;
        }

        if (target = nums[l])
            return l;
        else
            return -1;
    }
};
