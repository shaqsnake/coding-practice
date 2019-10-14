// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-20 18:32:42
 * @LastEditTime: 2019-09-21 09:37:28
 * @Description: Acwing 845
 */

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

int bfs(string start) {
    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> d;

    q.push(start);
    d[start] = 0;

    while (q.size()) {
        auto t = q.front();
        q.pop();
        int distance = d[t];
        if (t == end)
            return distance;

        int k = t.find("x");
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                swap(t[3 * x + y], t[3 * nx + ny]);
                if (!d.count(t)) {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[3 * x + y], t[3 * nx + ny]);
            }
        }
    }

    return -1;
}

int main() {
    // freopen("input.txt", "r", stdin);
    string start = "";
    for (int i = 0; i < 9; i++) {
        char c;
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;

    return 0;
}
