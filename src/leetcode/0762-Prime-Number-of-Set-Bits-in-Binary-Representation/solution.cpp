#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

        int res = 0;
        for (int i = L; i <= R; ++i) {
            int bit_cnt = 0;
            for (int j = i; j; j >>= 1) {
                bit_cnt += j & 1;
            }
            if (primes.count(bit_cnt)) {
                ++res;
            }
        }

        return res;
    }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
    string line;
    while (getline(cin, line)) {
        int L = stringToInteger(line);
        getline(cin, line);
        int R = stringToInteger(line);

        int ret = Solution().countPrimeSetBits(L, R);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}