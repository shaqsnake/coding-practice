// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-12 14:22:31
 * @LastEditTime: 2019-08-12 15:07:15
 * @Description: 151. Reverse Words in a String
 */

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, k = 0;
        while (i < s.size()) {
            while (s[i] == ' ') i++;
            if (i == s.size()) break;

            int j = i;
            while (j < s.size() && s[j] != ' ') j++;
            
            reverse(s.begin() + i, s.begin() + j);

            if (k) s[k++] = ' ';
            while (i < j) s[k++] = s[i++];
        }

        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());

        return s;
    }
};