#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    // DFS
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image.empty() || image[0].empty())
            return image;
        if (image[sr][sc] == newColor)
            return image;

        const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        const int m = image.size(), n = image[0].size();

        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        for (int i = 0; i < 4; ++i)
        {
            int x = sr + dx[i], y = sc + dy[i];
            if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == oldColor)
            {
                image = floodFill(image, x, y, newColor);
            }
        }

        return image;
    }

    // BFS
    vector<vector<int>> floodFill2(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image.empty() && image[0].empty())
            return image;
        if (image[sr][sc] == newColor)
            return image;

        const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        const int m = image.size(), n = image[0].size();
        pair<int, int> xy;
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        q.push(make_pair(sr, sc));
        visited[sr][sc] = 1;

        int oldColor = image[sr][sc];
        while (!q.empty())
        {
            xy = q.front();
            q.pop();
            image[xy.first][xy.second] = newColor;

            for (int i = 0; i < 4; ++i)
            {
                int x = xy.first + dx[i], y = xy.second + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == 0 && image[x][y] == oldColor)
                {
                    q.push(make_pair(x, y));
                    visited[xy.first][xy.second] = 1;
                }
            }
        }

        return image;
    }
};

int main()
{
    vector<vector<int>> img = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> res = Solution().floodFill2(img, 1, 1, 2);

    for (const auto &vec : res)
    {
        for (const auto &v : vec)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}