// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-17 15:07:01
 * @LastEditTime: 2019-09-17 16:26:43
 * @Description: Acwing 907
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;
struct Range {
    int l, r;
    bool operator<(const Range &rhs) { return l < rhs.l; }
} range[N];

int main() {
    int s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> range[i].l >> range[i].r;

    sort(range, range + n);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int j = i, right = -2e9;
        while (j < n && range[j].l <= s) {
            right = max(right, range[j].r);
            j++;
        }

        if (right < s) {
            res = -1;
            break;
        }

        res++;

        if (right >= t)
            break;

        s = right;
        i = j - 1;
    }

    cout << res << endl;

    return 0;
}