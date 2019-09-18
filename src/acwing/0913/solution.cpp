// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-18 09:49:29
 * @LastEditTime: 2019-09-18 14:13:08
 * @Description: Acwing 913
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;
int t[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];

    sort(t, t + n);

    long long res = 0;
    for (int i = 0; i < n; i++)
        res += t[i] * (n - i - 1);

    cout << res << endl;

    return 0;
}