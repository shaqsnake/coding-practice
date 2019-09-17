// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-17 17:30:04
 * @LastEditTime: 2019-09-17 17:46:06
 * @Description: Acwing 104
 */
#include <iostream>
#include <queue>

using namespace std;

const int N = 10010;

int main() {
    priority_queue<int, vector<int>, greater<int>> heap;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        heap.push(x);
    }

    int res = 0;
    while (heap.size() > 1) {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        heap.push(a + b);
        res += a + b;
    }

    cout << res << endl;

    return 0;
}