// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-07-24 16:10:11
 * @LastEditTime: 2019-07-24 16:13:56
 * @Description: leetcode#96
 */
class Solution {
public:
    int numTrees(int n) {
        long long res = 1;
        for (int i = n + 1; i <= 2 * n; i++)
            res = res * i / (i - n);

        return res / (n + 1);
    }
};