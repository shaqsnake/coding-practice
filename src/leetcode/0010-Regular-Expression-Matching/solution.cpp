// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 11:34:05
 * @LastEditTime: 2019-09-16 14:47:01
 * @Description: 10. Regular Expression Matching
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> f(n+1, vector<bool>(m+1));
        s = " " + s, p = " " + p;

        f[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (i > 0 && (p[j] == '.' || p[j] == s[i]))
                    f[i][j] = f[i][j] | f[i-1][j-1];
                if (p[j] == '*') {
                    if (j >= 2) 
                        f[i][j] = f[i][j] | f[i][j-2];
                    if (i > 0 && (p[j-1] == '.' || p[j-1] == s[i]))
                        f[i][j] = f[i][j] | f[i-1][j];
                }
            }

        return f[n][m];
    }
};
