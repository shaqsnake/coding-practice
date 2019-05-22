#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> res;

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

    res.push_back(x + 1);
    dfs(x + 1);
    res.pop_back();

    dfs(x + 1);

    return;
}

int main()
{
    cin >> n >> m;
    dfs(0);
    return 0;
}