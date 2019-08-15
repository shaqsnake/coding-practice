// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-15 15:57:24
 * @LastEditTime: 2019-08-15 16:05:32
 * @Description: 79. Word Search
 */

class Solution {
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;

        m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, string word, int k) {
        if (board[x][y] != word[k]) return false;
        if (k == word.size() - 1) return true;

        char c = board[x][y];
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] != '#') {
                if (dfs(board, nx, ny, word, k+1)) return true;
            }
        }
        board[x][y] = c;
        
        return false;
    }
};
