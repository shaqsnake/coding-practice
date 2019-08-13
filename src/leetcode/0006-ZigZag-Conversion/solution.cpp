// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-13 10:23:26
 * @LastEditTime: 2019-08-13 14:26:48
 * @Description: 6. ZigZag Conversion
 */

class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) return s;

        string res;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                for (int j = i; j < s.size(); j += 2 * (n - 1)) res += s[j];
            } else {
                for (int j = i, k = 2 * (n - 1) - i; j < s.size() || k < s.size(); j += 2 * (n - 1), k += 2 * (n - 1)) {
                    if (j < s.size()) res += s[j];
                    if (k < s.size()) res += s[k];
                }
            }
        }

        return res;
    }
};
