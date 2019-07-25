// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-07-25 20:50:48
 * @LastEditTime: 2019-07-25 20:52:48
 * @Description: 
 */
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (target <= nums[mid])
                r = mid;
            else
                l = mid + 1;
        }

        if (nums[l] < target)
            return l + 1;
        return l;
    }
};