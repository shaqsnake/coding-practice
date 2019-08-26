// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-06-10 17:41:50
 * @LastEditTime: 2019-08-26 10:30:11
 * @Description: 1. Two Sum
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (decltype(nums.size()) i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                return vector<int>{map[target - nums[i]], (int)i};
            }
            map[nums[i]] = i;
        }

        return vector<int>();
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i])) return {m[target - nums[i]], i};
            m[nums[i]] = i;
        }

        return {-1, -1};
    }
};
