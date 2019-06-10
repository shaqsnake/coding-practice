#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) { return n > 0 && (n & -n) == n; }
};

int main() {
    Solution solution;
    int inputs[] = {1, 16, 218};
    for (const auto &n : inputs) {
        cout << solution.isPowerOfTwo(n) << endl;
    }
}