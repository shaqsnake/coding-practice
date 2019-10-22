// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 09:55:08
 * @LastEditTime: 2019-10-22 12:41:50
 * @Description: Acwing 859
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;
int p[N];
int n, m;

struct Edge {
    int a, b, w;

    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }
} edges[M];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    sort(edges, edges + m);

    for (int i = 1; i <= n; i++)
        p[i] = i;

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            res += w;
            cnt++;
            p[pa] = pb;
        }
    }

    if (cnt < n - 1) return -1;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    int res = kruskal();
    if (res == -1) cout << "impossible" << endl;
    else cout << res << endl;

    return 0;
}
