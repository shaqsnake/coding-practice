// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-12 16:32:19
 * @LastEditTime: 2019-08-12 16:58:04
 * @Description: 5. Longest Palindromic Substring
 */

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i, k = i; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++)
                if (k - j + 1 > res.size()) res = s.substr(j, k - j + 1);
            for (int j = i, k = i + 1; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++)
                if (k - j + 1 > res.size()) res = s.substr(j, k - j + 1);
        }
        
        return res;
    }
};
