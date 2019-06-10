#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0)
            return a;
        return getSum(a ^ b, uint(a & b) << 1);
    }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
    string line;
    while (getline(cin, line)) {
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);

        int ret = Solution().getSum(a, b);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}