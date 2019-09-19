// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-18 19:04:24
 * @LastEditTime: 2019-09-19 14:46:11
 * @Description: Acwing 1015
 */
#include <cstring>
#include <iostream>

using namespace std;

const int N = 110;
int a[N][N], f[N][N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];

        int res = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];

        cout << f[n][m] << endl;
    }

    return 0;
}