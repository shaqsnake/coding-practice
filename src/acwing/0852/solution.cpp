// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 09:55:08
 * @LastEditTime: 2019-10-21 11:31:48
 * @Description: Acwing 852
 */
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 2010, M = 10010;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int dist[N], cnt[N];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }

    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
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

    bool res = spfa();
    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}