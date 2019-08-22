// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-22 15:22:51
 * @LastEditTime: 2019-08-22 15:29:07
 * @Description: 76. Minimum Window Substring
 */

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (const auto &c : t) map[c]++;
        int cnt = map.size();

        string res;
        for (int i = 0, j = 0, c = 0; i < s.size(); i++) {
            if (map[s[i]] == 1) c++;
            map[s[i]]--;

            while (map[s[j]] < 0) map[s[j++]]++;

            if (c == cnt) {
                if (res.empty() || res.size() > i - j + 1) res = s.substr(j, i - j + 1);
            }
        }

        return res;
    }
};
