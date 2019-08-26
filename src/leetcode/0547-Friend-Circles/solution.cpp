// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-26 16:44:18
 * @LastEditTime: 2019-08-26 16:54:30
 * @Description: 547. Friend Circles
 */

class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        for (int i = 0; i < n; i++) p.push_back(i);

        int res = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (M[i][j] == 1) {
                    if (find(i) != find(j)) {
                        p[find(i)] = find(j);
                        res--;
                    }
                }
            }
        }

        return res;
    }
};
