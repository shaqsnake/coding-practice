#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // BFS
    int numSquares(int n) {
        queue<int> q;
        q.push(0);
        vector<int> v(n + 1, n);
        v[0] = 0;

        while (!q.empty()) {
            int t = q.front();
            if (t == n)
                break;
            q.pop();
            for (int i = 0; i * i + t <= n; ++i) {
                if (v[i * i + t] > v[t] + 1) {
                    v[i * i + t] = v[t] + 1;
                    q.push(i * i + t);
                }
            }
        }

        return v[n];
    }

    // DP f(i) = min(f(i), f(i-j*j) + 1)
    int numSquares2(int n) {
        vector<int> f(n + 1, n);
        f[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                f[i] = min(f[i], f[i - j * j] + 1);
            }
        }

        return f[n];
    }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().numSquares(n);
        int ret2 = Solution().numSquares2(n);

        string out = to_string(ret);
        cout << out << endl;
        string out2 = to_string(ret2);
        cout << out2 << endl;
    }
    return 0;
}