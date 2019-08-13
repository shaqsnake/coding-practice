// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-13 15:09:38
 * @LastEditTime: 2019-08-13 15:13:28
 * @Description: 3. Longest Substring Without Repeating Characters
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            map[s[i]]++;
            while (map[s[i]] > 1) map[s[j++]]--;
            res = max(res, i - j + 1);
        }

        return res;
    }

    int lengthOfLongestSubstring2(string s) {
        unordered_set<char> set;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while (j < s.size() && !set.count(s[j]))
                set.insert(s[j++]);
            res = max(res, j - i);
            set.clear();
        }
        
        return res;
    }
};
