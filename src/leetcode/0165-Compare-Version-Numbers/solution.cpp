// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-12 15:44:02
 * @LastEditTime: 2019-08-12 15:50:44
 * @Description: 165. Compare Version Numbers
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, k = 0;
        while (i < version1.size() || k < version2.size()) {
            int j = i, l = k;
            while (j < version1.size() && version1[j] != '.') j++;
            while (l < version2.size() && version2[l] != '.') l++;

            int v1 = i == j ? 0 : atoi(version1.substr(i, j - i).c_str());
            int v2 = k == l ? 0 : atoi(version2.substr(k, l - k).c_str());
            
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;

            i = j + 1;
            k = l + 1;
        }

        return 0;
    }
};