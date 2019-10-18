// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 09:55:08
 * @LastEditTime: 2019-10-18 18:45:14
 * @Description: Acwing 853
 */
#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;
int dist[N], backup[N];
int n, m, k;

struct Edge {
    int a, b, w;
} edges[M];

int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < k; i++) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    int res = bellman_ford();
    if (res == -1) cout << "impossible" << endl;
    else cout << res << endl;

    return 0;
}