#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &board, int x, int y, int m, int n) {
        board[x][y] = 'Y';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                board[nx][ny] == 'O') {
                dfs(board, nx, ny, m, n);
            }
        }

        return;
    }

    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty())
            return;

        const int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O')
                dfs(board, i, 0, m, n);
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1, m, n);
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O')
                dfs(board, 0, j, m, n);
            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j, m, n);
        }

        for (auto &vec : board) {
            for (auto &v : vec) {
                if (v == 'O') {
                    v = 'X';
                }
                if (v == 'Y') {
                    v = 'O';
                }
            }
        }

        return;
    }

private:
    const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
};

int main() {
    vector<vector<char>> b = {{'X', 'O', 'X', 'O', 'X', 'O'},
                              {'O', 'X', 'O', 'X', 'O', 'X'},
                              {'X', 'O', 'X', 'O', 'X', 'O'},
                              {'O', 'X', 'O', 'X', 'O', 'X'}};
    Solution().solve(b);
    for (const auto &vec : b) {
        for (const auto &v : vec) {
            cout << v << " ";
        }
        cout << endl;
    }
}