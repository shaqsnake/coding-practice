// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-22 16:33:02
 * @LastEditTime: 2019-08-22 16:47:57
 * @Description: 32. Longest Valid Parentheses
 */

class Solution {
public:
    unordered_map<char, int> m{{'(', 1}, {')', -1}};

    int work(string s) {
        int sum = 0, res = 0;

        for (int i = 0, j = 0; i < s.size(); i++) {
            sum += m[s[i]];
            if (sum < 0) {
                j = i + 1;
                sum = 0;
            } else if (sum == 0) {
                res = max(res, i - j + 1);
            }
        }

        return res;
    }

    int longestValidParentheses(string s) {
        int res = work(s);
        reverse(s.begin(), s.end());
        for (auto &c : s) c ^= 1;
        return max(res, work(s));
    }
};
