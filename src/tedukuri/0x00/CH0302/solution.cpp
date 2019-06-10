#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> res;

void dfs(int x) {
    if (res.size() > m || res.size() + n - x < m)
        return;
    if (res.size() == m) {
        for (const auto &r : res)
            cout << r << " ";
        cout << endl;
        return;
    }

    res.push_back(x + 1);
    dfs(x + 1);
    res.pop_back();

    dfs(x + 1);

    return;
}

void dfs2(int x, int state, int size) {
    if (size > m || size + n - x < m)
        return;
    if (size == m) {
        for (int i = 0; i < n; i++)
            if (state >> i & 1)
                cout << i + 1 << " ";
        cout << endl;
        return;
    }

    dfs2(x + 1, state | (1 << x), size + 1); // choose
    dfs2(x + 1, state, size);                // not choose
    return;
}

int main() {
    cin >> n >> m;
    dfs(0);
    dfs2(0, 0, 0);
    return 0;
}