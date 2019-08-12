// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-12 11:07:59
 * @LastEditTime: 2019-08-12 11:11:39
 * @Description: 38. Count and Say
 */

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            string s;
            for (int j = 0; j < res.size();) {
                int k = j;
                while (k < res.size() && res[j] == res[k]) k++;
                s += to_string(k - j) + res[j];
                j = k;
            }
            res = s;
        }

        return res;
    }
};
