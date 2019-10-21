// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 09:55:08
 * @LastEditTime: 2019-10-21 12:51:42
 * @Description: Acwing 854
 */
#include <iostream>

using namespace std;

const int N = 210;
int d[N][N], INF = 1e9;
int n, m, q;

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    return;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }

    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }

    floyd();

    while (q--) {
        int x, y;
        cin >> x >> y;
        int res = d[x][y];

        if (res < INF / 2)
            cout << d[x][y] << endl;
        else
            cout << "impossible" << endl;
    }

    return 0;
}
