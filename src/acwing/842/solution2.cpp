// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-20 11:06:06
 * @LastEditTime: 2019-09-20 11:52:20
 * @Description: Acwing 842
 */
#include <iostream>
#include <vector>

using namespace std;

const int N = 10;
int path[N];
int n;

void dfs(int x, int st) {
    if (x == n) {
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!(st >> i & 1)) {
            path[x] = i + 1;
            dfs(x + 1, st + (1 << i));
        }
    }
}

int main() {
    cin >> n;

    dfs(0, 0);

    return 0;
}