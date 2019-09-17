// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-16 16:25:22
 * @LastEditTime: 2019-09-17 10:27:33
 * @Description: Acwing 905
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;
struct Range {
    int l, r;

    bool operator<(const Range &rhs) { return r < rhs.r; }
} range[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> range[i].l >> range[i].r;
    }

    sort(range, range + n);

    int res = 0, p = -2e9;
    for (int i = 0; i < n; i++)
        if (range[i].l > p) {
            ++res;
            p = range[i].r;
        }

    cout << res << endl;

    return 0;
}