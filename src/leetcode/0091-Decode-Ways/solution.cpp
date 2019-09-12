// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-09-12 15:25:17
 * @LastEditTime: 2019-09-12 15:40:27
 * @Description: 91. Decode Ways
 */

class Solution {
public:
    int numDecodings(string s) {
       int n = s.size();
       vector<int> f(n+1);

       f[0] = 1;
       for (int i = 1; i <= n; i++) {
           if (s[i-1] != '0') f[i] += f[i-1];
           if (i >= 2) {
               int t = (s[i-2] - '0') * 10 + (s[i-1] - '0');
               if (t >= 10 && t <= 26) f[i] += f[i-2];
           }
       }

       return f[n];
    }
};
