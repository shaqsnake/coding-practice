// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-19 17:05:49
 * @LastEditTime: 2019-08-19 17:11:16
 * @Description: 52. N-Queens II
 */

class Solution {
public:
    vector<bool> col, dial, ndial;
    int res;

    int totalNQueens(int n) {
        col = vector<bool>(n);
        dial = ndial = vector<bool>(2 * n);

        dfs(0, n);
        return res;    
    }

    void dfs(int x, int n) {
        if (x == n) {
            res++;
            return;
        }

        for (int y = 0; y < n; y++) {
            if (!col[y] && !dial[x + y] && !ndial[x - y + n]) {
                col[y] = dial[x + y] = ndial[x - y + n] = true;
                dfs(x + 1, n);
                col[y] = dial[x + y] = ndial[x - y + n] = false;
            }
        }
    }
};

