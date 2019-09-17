// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-17 14:42:59
 * @LastEditTime: 2019-09-17 14:43:39
 * @Description: Acwing 906
 */
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int N = 100010;
struct Range {
    int l, r;
    bool operator<(const Range &rhs) { return l < rhs.l; }
} range[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> range[i].l >> range[i].r;

    sort(range, range + n);

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++) {
        if (heap.empty() || range[i].l <= heap.top()) {
            heap.push(range[i].r);
        } else {
            heap.pop();
            heap.push(range[i].r);
        }
    }

    cout << heap.size() << endl;

    return 0;
}