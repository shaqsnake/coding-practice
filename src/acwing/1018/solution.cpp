// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-19 10:57:01
 * @LastEditTime: 2019-09-19 14:50:09
 * @Description: Acwing 1018
 */

#include <iostream>

using namespace std;

const int N = 110;
int w[N][N], f[N][N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            f[i][j] = 1e9;
            if (!i && !j)
                f[i][j] = w[i][j];
            if (i > 0)
                f[i][j] = min(f[i][j], f[i - 1][j] + w[i][j]);
            if (j > 0)
                f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]);
        }

    cout << f[n - 1][n - 1] << endl;

    return 0;
}
