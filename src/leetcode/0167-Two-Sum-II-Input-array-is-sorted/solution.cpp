// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-22 09:20:35
 * @LastEditTime: 2019-08-22 09:24:27
 * @Description: 167. Two Sum II - Input array is sorted
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0, j = numbers.size() - 1; i < numbers.size(); i++) {
            while (j - 1 > i && numbers[j - 1] + numbers[i] >= target)
                j--;
            if (numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
        }

        return {-1, -1};
    }
};
