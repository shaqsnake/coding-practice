// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 09:55:08
 * @LastEditTime: 2019-10-22 12:41:50
 * @Description: Acwing 861
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];
int n1, n2, m;

void add(int a, int b) {
    e[idx] = b, ne[idx]= h[a], h[a] = idx++;
}

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    memset(h, -1, sizeof h);
    cin >> n1 >> n2 >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }

    cout << res << endl;

    return 0;
}
