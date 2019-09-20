// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-20 11:06:06
 * @LastEditTime: 2019-09-20 11:48:06
 * @Description: Acwing 842
 */
#include <iostream>
#include <vector>

using namespace std;

const int N = 10;
bool st[N];
vector<int> res;
int n;

void dfs(int x) {
    if (x == n) {
        for (const auto &r : res)
            cout << r << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!st[i]) {
            res.push_back(i + 1);
            st[i] = true;
            dfs(x + 1);
            st[i] = false;
            res.pop_back();
        }
    }
}

int main() {
    cin >> n;

    dfs(0);

    return 0;
}