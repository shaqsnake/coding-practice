#include <iostream>
#include <vector>

using namespace std;

int n, visited[9];
vector<int> res;

void dfs(int x) {
    if (x == n) {
        for (const auto &r : res)
            cout << r << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            res.push_back(i + 1);
            visited[i] = 1;
            dfs(x + 1);
            res.pop_back();
            visited[i] = 0;
        }
    }
}

void dfs2(int x, int state) {
    if (x == n) {
        for (const auto &r : res)
            cout << r << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!(state >> i & 1)) {
            res.push_back(i + 1);
            dfs2(x + 1, state | (1 << i));
            res.pop_back();
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << endl;
    dfs2(0, 0);
    return 0;
}