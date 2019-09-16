// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 14:55:47
 * @LastEditTime: 2019-09-16 15:22:02
 * @Description: 664. Strange Printer
 */

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> f(n+2, vector<int>(n+2));

        for (int len = 1; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                f[l][r] = 1 + f[l+1][r];
                for (int k = l + 1; k <= r; k++) {
                    if (s[k-1] == s[l-1]) f[l][r] = min(f[l][r], f[l][k-1] + f[k+1][r]);
                }
            }
        }

        return f[1][n];
    }
};
