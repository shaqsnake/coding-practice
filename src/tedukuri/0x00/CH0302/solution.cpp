#include <iostream>

using namespace std;

int n, m;

void dfs(int x)
{
    if (res.size() > m || res.size() + n - x < m)
        return;
    if (res.size() == m)
    {
        for (const auto &r : res)
            cout << r << " ";
        cout << endl;
        return;
    }

    dfs(x + 1);

    res.push_back(x + 1);
    dfs(x + 1);
    res.pop_back();

    return;
}

int main()
{
    cin >> n >> m;
    dfs(0, 0);
    return 0;
}