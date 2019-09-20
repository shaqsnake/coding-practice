// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-20 15:56:35
 * @LastEditTime: 2019-09-20 16:59:15
 * @Description: Acing 843
 */
#include <iostream>

using namespace std;

const int N = 10;
char g[N][N];
bool row[N], col[N], dg[2 * N], ndg[2 * N];
int n;

void dfs(int x, int y, int q) {
    if (y == n) y = 0, x++;
    if (x == n) {
        if (q == n) {
            for (int i = 0; i < n; i++)
                cout << g[i] << endl;
            cout << endl;
        }
        return;
    }

    // Not choose (x, y)
    dfs(x, y + 1, q);

    // Choose (x, y)
    if (!row[x] && !col[y] && !dg[x + y] && !ndg[x - y + n]) {
        row[x] = col[y] = dg[x + y] = ndg[x - y + n] = true;
        g[x][y] = 'Q';
        dfs(x + 1, 0, q + 1); // Skip to next row.
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = ndg[x - y + n] = false;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0, 0, 0);

    return 0;
}