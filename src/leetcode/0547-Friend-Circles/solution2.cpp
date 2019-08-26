// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-06-11 18:23:09
 * @LastEditTime: 2019-08-26 16:41:59
 * @Description: 547. Friend Circles
 */
class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        if (M.empty() || M[0].empty())
            return 0;

        int n = M.size();
        for (int i = 1; i <= n; i++)
            p[i] = i;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (M[i][j] == 1)
                    uni(i + 1, j + 1);

        int res = 0;
        for (int i = 1; i <= n; i++)
            if (i == p[i])
                res++;
        return res;
    }

private:
    int p[1210];

    void uni(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py)
            p[px] = py;
    }

    int find(int x) {
        if (x != p[x])
            p[x] = find(p[x]);
        return p[x];
    }
};