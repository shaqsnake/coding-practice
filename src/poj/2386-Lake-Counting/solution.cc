#include <cstdio>
#include <iostream>

using namespace std;

const int N = 110, M = 110;
char g[N][M];

void dfs(int x, int y, int n, int m) {
    g[x][y] = '.';
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1},
        dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 'W') {
            dfs(nx, ny, n, m);
        }
    }

    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'W') {
                res++;
                dfs(i, j, n, m);
            }
        }
    }

    cout << res << endl;

    return 0;
}