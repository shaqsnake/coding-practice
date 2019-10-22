// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 09:55:08
 * @LastEditTime: 2019-10-22 11:06:13
 * @Description: Acwing 858
 */
#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return -1;

        st[t] = true;
        if (i) res += dist[t];

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);

    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    // memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = (i == j ? 0 : INF);
    
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }

    int res = prim();
    if (res == -1) cout << "impossible" << endl;
    else cout << res << endl;

    return 0;
}
