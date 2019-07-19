// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-07-19 17:58:41
 * @LastEditTime: 2019-07-19 18:02:15
 * @Description:
 */
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;

        for (int i = 0; i < 3; i++) {
            while (num % primes_[i] == 0) {
                num /= primes_[i];
            }
        }

        return num == 1;
    }

private:
    int primes_[3] = {2, 3, 5};
};