// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 09:55:08
 * @LastEditTime: 2019-10-17 10:41:59
 * @Description: Acwing 849
 */
#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int g[N][N];
int d[N];
int st[N];
int n, m;
int path[N];

int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    for (int i = 0; i < n; i++) {
        // Find the minimum vertex from the rest
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || d[t] > d[j]))
                t = j;

        // Put the vertex into set
        st[t] = true;

        // Update all rest vertexes' weight
        for (int j = 1; j <= n; j++) {
            if (!st[j]) {
                d[j] = min(d[j], d[t] + g[t][j]);
                path[j] = t;
            }
        }
    }

    if (d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}

int main() {
    // freopen("input.txt", "r", stdin);
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }

    cout << dijkstra() << endl;

    // Output the shortest path in reverse.
    while (n != path[n]) {
        cout << n << " ";
        n = path[n];
    } 
    cout << endl;

    return 0;
}
