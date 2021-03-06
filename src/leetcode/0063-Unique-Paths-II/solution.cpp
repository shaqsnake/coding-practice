// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-12 14:33:28
 * @LastEditTime: 2019-09-12 14:48:02
 * @Description: 63. Unique Paths II
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long long>> f(n, vector<long long>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j]) continue;
                if (!i && !j) f[i][j] = 1;
                if (i > 0) f[i][j] += f[i-1][j];
                if (j > 0) f[i][j] += f[i][j-1];
            }

        return f[n-1][m-1];
    }
};
