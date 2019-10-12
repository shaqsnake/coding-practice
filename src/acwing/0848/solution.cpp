// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-30 18:15:31
 * @LastEditTime: 2019-09-30 18:18:55
 * @Description: Acwing 848
 */
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], idx;
int d[N];
int n, m;
vector<int> res;
int q[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    d[b]++;
}

bool bfs() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (d[i] == 0)
            q.push(i);
    }

    while (q.size()) {
        auto t = q.front();
        q.pop();
        res.push_back(t);

        for (int i = h[t]; i != -1; i = ne[i]) {
            int v = e[i];
            if (--d[v] == 0)
                q.push(v);
        }
    }

    return res.size() == n;
}

int main() {
    freopen("input.txt", "r", stdin);
    memset(h, -1, sizeof h);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    if (bfs()) {
        for (const auto r : res)
            cout << r << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
