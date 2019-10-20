// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-10-17 09:55:08
 * @LastEditTime: 2019-10-17 10:41:59
 * @Description: Acwing 851
 */
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int d[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    
    queue<int> q;
    q.push(1);
    st[1] = true;
    
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
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
    
    int res = spfa();
    if (res == -1) cout << "impossible" << endl;
    else cout << res << endl;
    
    return 0;
}