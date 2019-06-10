class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        // 2*31 - 1 = 2,147,483,647
        for (int i = 30; i >= 0; --i) {
            if ((m >> i & 1) ^ (n >> i & 1)) // find the first different bit
            {
                break;
            }
            res += (m >> i & 1) << i;
        }

        return res;
    }
};

int stringToInteger(string input) { return stoi(input); }

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        int ret = Solution().rangeBitwiseAnd(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}