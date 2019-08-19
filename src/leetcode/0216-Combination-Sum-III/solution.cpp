// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-19 15:28:10
 * @LastEditTime: 2019-08-19 15:39:15
 * @Description: 216. Combination Sum III
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
    }

    void dfs(int k, int n, int start) {
        if (!k) {
            if (!n) res.push_back(path);
            return;
        }

        // 9 - i + 1 >= k
        for (int i = start; i <= 10 - k; i++) {
            path.push_back(i);
            dfs(k - 1, n - i, i + 1);
            path.pop_back();
        }
    }
};