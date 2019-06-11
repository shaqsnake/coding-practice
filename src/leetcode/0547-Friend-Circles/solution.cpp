class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        if (M.empty() || M[0].empty())
            return 0;

        int n = M.size();
        for (int i = 1; i <= n; i++)
            p[i] = i;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (M[i][j] == 1)
                    uni(i + 1, j + 1);

        int res = 0;
        for (int i = 1; i <= n; i++)
            if (i == p[i])
                res++;
        return res;
    }

private:
    int p[1210];

    void uni(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py)
            p[px] = py;
    }

    int find(int x) {
        if (x != p[x])
            p[x] = find(p[x]);
        return p[x];
    }
};