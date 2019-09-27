// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-27 14:30:57
 * @LastEditTime: 2019-09-27 15:32:22
 * @Description: Acwing 846
 */
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;
int h[N], e[N * 2], ne[N * 2], idx;
int st[N];
int n, ans = N;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

int dfs(int u) {
    st[u] = true;
    int res = 0, sum = 1;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int v = e[i];
        if (!st[v]) {
            int size = dfs(v);
            res = max(res, size);
            sum += size;
        }
    }

    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n;

    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}