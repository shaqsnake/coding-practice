// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 09:55:08
 * @LastEditTime: 2019-10-22 12:41:50
 * @Description: Acwing 860
 */

#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = 200010;
int h[N], e[M], ne[M], idx;
int color[N];
int n, m;

int add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool dfs(int x, int c) {
    color[x] = c;

    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!color[j]) {
            if (!dfs(j, 3 - c))
                return false;
        } else if (color[j] == c)
            return false;
    }

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}