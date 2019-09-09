// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-09 11:09:36
 * @LastEditTime: 2019-09-09 11:28:18
 * @Description: 72. Edit Distance
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));

        for (int i = 1; i <= n; i++) f[i][0] = i;
        for (int j = 1; j <= m; j++) f[0][j] = j;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1);
                if (word1[i-1] == word2[j-1]) f[i][j] = min(f[i][j], f[i-1][j-1]);
                else f[i][j] = min(f[i][j], f[i-1][j-1] + 1);
            }
        
        return f[n][m];
    }
};
