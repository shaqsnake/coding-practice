// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-12 14:07:32
 * @LastEditTime: 2019-08-12 14:15:48
 * @Description: 49. Group Anagrams
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (const auto &s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto &m : map) {
            res.push_back(m.second);
        }

        return res;
    }
};
