// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-19 17:12:21
 * @LastEditTime: 2019-09-19 17:16:15
 * @Description: Acwing 1027
 */
#include <iostream>

using namespace std;

const int N = 10;
int w[N][N], f[N * 2][N][N];

int main() {
    int n;
    cin >> n;
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c) {
        w[a][b] = c;
    }

    for (int k = 2; k <= n + n; k++) {
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
                    int t = w[i1][j1];
                    if (i1 != i2)
                        t += w[i2][j2];
                    int &u = f[k][i1][i2];
                    u = max(u, f[k - 1][i1 - 1][i2 - 1] + t);
                    u = max(u, f[k - 1][i1 - 1][i2] + t);
                    u = max(u, f[k - 1][i1][i2 - 1] + t);
                    u = max(u, f[k - 1][i1][i2] + t);
                }
            }
        }
    }

    cout << f[2 * n][n][n] << endl;

    return 0;
}