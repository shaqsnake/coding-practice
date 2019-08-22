// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-22 11:16:26
 * @LastEditTime: 2019-08-22 11:19:43
 * @Description: 26. Remove Duplicates from Sorted Array
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 1;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j- 1] != nums[j]) nums[i++] = nums[j];
        }

        return i;
    }
};
