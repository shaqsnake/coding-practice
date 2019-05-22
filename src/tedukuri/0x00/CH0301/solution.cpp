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

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}