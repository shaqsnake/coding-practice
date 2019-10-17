// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 09:55:08
 * @LastEditTime: 2019-10-17 10:41:59
 * @Description: Acwing 850
 */
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int d[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int dist = t.first, vert = t.second;

        if (st[vert]) continue;
        st[vert] = true;

        for (int i = h[vert]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > dist + w[i]) {
                d[j] = dist + w[i];
                heap.push({d[j], j});
            }
        }
    }

    if (d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}

int main() {
    // freopen("input.txt", "r", stdin);
    memset(h, -1, sizeof h);

    cin >> n >> m;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }

    cout << dijkstra() << endl;

    return 0;
}