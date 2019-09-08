// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-08 14:04:50
 * @LastEditTime: 2019-09-08 14:50:47
 * @Description: 120. Triangle
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));

        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= i; j++) {
                f[i][j] = INT_MAX;
                if (j > 0) f[i][j] = min(f[i][j], f[i-1][j-1] + triangle[i][j]);
                if (j != i) f[i][j] = min(f[i][j], f[i-1][j] + triangle[i][j]);
            }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) res = min(res, f[n-1][i]);
        return res;
    }

    int minimumTotal2(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(2, vector<int>(n));

        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= i; j++) {
                f[i & 1][j] = INT_MAX;
                if (j > 0) f[i & 1][j] = min(f[i & 1][j], f[i-1 & 1][j-1] + triangle[i][j]);
                if (j != i) f[i & 1][j] = min(f[i & 1][j], f[i-1 & 1][j] + triangle[i][j]);
            }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) res = min(res, f[n-1 & 1][i]);
        return res;
    }

    int minimumTotal3(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);

        return triangle[0][0];
    }
};
