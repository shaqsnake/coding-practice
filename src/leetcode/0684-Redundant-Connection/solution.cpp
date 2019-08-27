// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-27 09:33:06
 * @LastEditTime: 2019-08-27 11:17:40
 * @Description: 684. Redundant Connection
 */

class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i = 0; i <= n; i++) p.push_back(i);

        for (const auto &e : edges) {
            int a = e[0], b = e[1];
            if (find(a) == find(b)) return {a, b};
            else p[find(a)] = find(b);
        }

        return {-1, -1};
    }
};
