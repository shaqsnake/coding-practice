#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &grid, int x, int y, int m, int n) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                dfs(grid, nx, ny, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        const int m = grid.size(), n = grid[0].size();

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return res;
    }

private:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
};

int main() {
    vector<vector<char>> g = {{'1', '1', '1', '1', '0'},
                              {'1', '1', '0', '1', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '0', '0', '0'}};
    int res = Solution().numIslands(g);
    cout << res << endl;

    vector<vector<char>> g2 = {{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '0', '0', '1', '1'}};
    res = Solution().numIslands(g2);

    cout << res << endl;
}