// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-14 14:28:17
 * @LastEditTime: 2019-09-14 15:31:02
 * @Description: 518. Coin Change 2
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> f(n + 1, vector<int>(amount + 1));

        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i][0] = 1;
            for (int j = 1; j <= amount; j++) {
                for (int k = 0; k * coins[i-1] <= j; k++) {
                    f[i][j] += f[i-1][j - k * coins[i-1]];
                }
            }
        }

        return f[n][amount];
    }

    int change(int amount, vector<int>& coins) {
        vector<int> f(amount + 1);

        f[0] = 1;
        for (const auto &c : coins)
            for (int j = c; j <= amount; j++)
                f[j] += f[j-c];

        return f[amount];
    }
};
