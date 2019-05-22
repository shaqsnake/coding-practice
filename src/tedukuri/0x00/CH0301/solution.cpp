#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> res;

void dfs(int x)
{
    if (x == n)
    {
        for (const auto &r : res)
            cout << r << " ";
        cout << endl;
        return;
    }

    dfs(x + 1); // 不选择x，继续搜索

    res.push_back(x + 1); // 选择x
    dfs(x + 1); // 继续搜索
    res.pop_back(); // 回溯时还原现场

    return;
}

void dfs2(int x, int state) {
    if (x == n) {
        for (int i = 0; i < n; ++i)
            if (state >> i & 1) 
                cout << i + 1 << " ";
        cout << endl;
        return;
    }

    dfs2(x+1, state); // not choose and search next
    dfs2(x+1, state | (1 << x)); // choose and search next
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}