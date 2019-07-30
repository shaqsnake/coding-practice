// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-07-27 17:51:05
 * @LastEditTime: 2019-07-29 17:48:27
 * @Description: 153. Find Minimum in Rotated Sorted Array
 */
class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.back() > nums[0])
            return nums[0];
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= nums[0])
                l = mid + 1;
            else
                r = mid;
        }

        return nums[l];
    }

    int findMin2(vector<int> &nums) {
        if (nums.back() > nums[0])
            return nums[0];
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] <= nums.back())
                r = mid;
            else
                l = mid + 1;
        }

        return nums[r];
    }
};