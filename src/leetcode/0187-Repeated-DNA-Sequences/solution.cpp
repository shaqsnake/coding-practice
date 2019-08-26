// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-26 10:47:01
 * @LastEditTime: 2019-08-26 11:02:07
 * @Description: 187. Repeated DNA Sequences
 */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;

        vector<string> res;
        for (int i = 0; i + 10 <= s.size(); i++) {
            string str = s.substr(i, 10);
            m[str]++;
            if (m[str] == 2) res.push_back(str);
        }

        return res;
    }
};
