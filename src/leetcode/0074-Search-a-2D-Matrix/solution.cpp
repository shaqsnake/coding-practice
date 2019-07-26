// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-07-26 10:50:29
 * @LastEditTime: 2019-07-26 10:55:34
 * @Description: 74. Search a 2D Matrix
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (target <= matrix[mid / n][mid % n])
                r = mid;
            else
                l = mid + 1;
        }

        return matrix[l / n][l % n] == target;
    }
};