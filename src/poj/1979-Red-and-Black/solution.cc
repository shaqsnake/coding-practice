#include <iostream>

using namespace std;

const int W = 20, H = 20;
char g[W][H];

void dfs(int x, int y, int m, int n, int &res) {
    res++;
    g[x][y] = 'X';
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] == '.')
            dfs(nx, ny, m, n, res);
    }
    return;
}

int main() {
    int h, w, sx, sy;
    while (cin >> h >> w) {
        if (!h || !w)
            break;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                cin >> g[i][j];
                if (g[i][j] == '@')
                    sx = i, sy = j;
            }
        }

        int res = 0;
        dfs(sx, sy, w, h, res);

        cout << res << endl;
    }

    return 0;
}