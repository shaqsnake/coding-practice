#include <iostream>
#include <vector>

using namespace std;

int n, visited[9];
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

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            res.push_back(i + 1);
            visited[i] = 1;
            dfs(x + 1);
            res.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}