// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-06 16:03:05
 * @LastEditTime: 2019-08-06 16:04:38
 * @Description: 275. H-Index II
 */
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int l = 0, r = citations.size();
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (citations[citations.size() - mid] >= mid)
                l = mid;
            else
                r = mid - 1;
        }

        return r;
    }
};