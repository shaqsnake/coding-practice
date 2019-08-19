// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-19 11:31:39
 * @LastEditTime: 2019-08-19 11:41:18
 * @Description: 78. Subsets
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        for (int i = 0; i < 1 << nums.size(); i++) {
            vector<int> tmp;
            for (int j = 0; j < nums.size(); j++) {
                if (i >> j & 1) tmp.push_back(nums[j]);
            }

            res.push_back(tmp);
        }

        return res;
    }
};
