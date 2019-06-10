#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        for (const auto &n : nums) {
            int p = 0;
            for (int i = 30; i >= 0; --i) {
                int t = n >> i & 1;
                if (!trie[p].children[t]) {
                    trie.push_back({0, 0});
                    trie[p].children[t] = trie.size() - 1;
                }
                p = trie[p].children[t];
            }
        }

        int res = 0;
        for (const auto &n : nums) {
            int p = 0, xor_sum = 0;
            for (int i = 30; i >= 0; --i) {
                int t = n >> i & 1;
                if (trie[p].children[!t]) {
                    p = trie[p].children[!t];
                    xor_sum += 1 << i;
                } else {
                    p = trie[p].children[t];
                }
            }
            res = max(res, xor_sum);
        }

        return res;
    }

private:
    struct Node {
        int children[2];
    };
    vector<Node> trie = {{0, 0}};
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().findMaximumXOR(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}