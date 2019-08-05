// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-01 17:38:47
 * @LastEditTime: 2019-08-05 17:22:47
 * @Description: 162. Find Peak Element
 */
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid - 1] <= nums[mid])
                l = mid;
            else
                r = mid - 1;
        }

        return r;
    }

    int findPeakElement2(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};