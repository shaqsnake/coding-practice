// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-30 18:15:31
 * @LastEditTime: 2019-09-30 18:18:55
 * @Description: Acwing 847
 */
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], idx;
int f[N];
int n, m;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

int bfs() {
    memset(f, -1, sizeof f);

    queue<int> q;
    f[1] = 0;
    q.push(1);
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int v = e[i];
            if (f[v] == -1) {
                f[v] = f[t] + 1;
                q.push(v);
            }
        }
    }

    return f[n];
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}