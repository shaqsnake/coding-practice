class Solution {
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        string state;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                state += to_string(board[i][j]);

        q.push(state);
        return bfs();
    }

private:
    queue<string> q;
    unordered_map<string, int> d;
    int bfs();
};

int Solution::bfs() {
    while (q.size()) {
        auto t = q.front();
        if (t == "123450")
            return d[t];

        q.pop();
        int k = t.find('0');
        int distance = d[t];
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nx = k / 3 + dx[i], ny = k % 3 + dy[i];
            if (nx >= 0 && nx < 2 && ny >= 0 && ny < 3) {
                swap(t[k], t[nx * 3 + ny]);
                if (d.find(t) == d.end()) {
                    q.push(t);
                    d[t] = distance + 1;
                }
                swap(t[k], t[nx * 3 + ny]);
            }
        }
    }
    return -1;
}