// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-07-17 14:26:05
 * @LastEditTime: 2019-07-17 14:26:05
 * @Description: 
 */
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (z <= x + y && z % gcd(x, y) == 0);
    }

private:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
};