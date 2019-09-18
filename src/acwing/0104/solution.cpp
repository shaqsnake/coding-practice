// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-18 14:14:56
 * @LastEditTime: 2019-09-18 14:19:52
 * @Description: Acwing 104
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int res = 0;
    for (int i = 0; i < n; i++)
        res += abs(a[i] - a[n / 2]);
    cout << res << endl;

    return 0;
}