// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-20 15:56:35
 * @LastEditTime: 2019-09-20 16:25:28
 * @Description: Acwing 843
 */
#include <iostream>

using namespace std;

const int N = 10;
char g[N][N];
bool col[N], dg[2 * N], ndg[2 * N];
int n;

void dfs(int x) {
    if (x == n) {
        for (int i = 0; i < n; i++)
            cout << g[i] << endl;
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[i + x] && !ndg[i - x + n]) {
            col[i] = dg[i + x] = ndg[i - x + n] = true;
            g[x][i] = 'Q';
            dfs(x + 1);
            g[x][i] = '.';
            col[i] = dg[i + x] = ndg[i - x + n] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0);

    return 0;
}