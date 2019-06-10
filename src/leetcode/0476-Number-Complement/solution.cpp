#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {

        int res = 0, t = 0;
        while (num) {
            res += !(num & 1) << t;
            num >>= 1;
            ++t;
        }

        return res;
    }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        int ret = Solution().findComplement(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}