// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-20 18:32:42
 * @LastEditTime: 2019-09-21 09:37:28
 * @Description: Acwing 844
 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 110;
int g[N][N], f[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m;

int bfs() {
    memset(f, -1, sizeof f);
    f[0][0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 0 &&
                f[nx][ny] == -1) {
                f[nx][ny] = f[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return f[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}
