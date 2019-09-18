// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-18 15:17:41
 * @LastEditTime: 2019-09-18 15:25:28
 * @Description: Acwing 125
 */
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 50010;
PII cow[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, s;
        cin >> w >> s;
        cow[i] = {w + s, w};
    }

    sort(cow, cow + n);

    int res = -2e9, sum = 0;
    for (int i = 0; i < n; i++) {
        int w = cow[i].second, s = cow[i].first - cow[i].second;
        res = max(res, sum - s);
        sum += w;
    }

    cout << res << endl;

    return 0;
}