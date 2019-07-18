// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-07-18 16:09:56
 * @LastEditTime: 2019-07-18 16:15:30
 * @Description:
 */
class Solution {
public:
    int superPow(int a, vector<int> &b) {
        if (b.empty())
            return 1;
        int idx = b.back();
        b.pop_back();
        return qmi(superPow(a, b), 10, 1337) * qmi(a, idx, 1337) % 1337;
    }

private:
    int qmi(int a, int b, int p) {
        int res = 1;
        while (b) {
            if (b & 1)
                res = static_cast<long long>(res) * a % p;
            b >>= 1;
            a = static_cast<long long>(a) * a % p;
        }

        return res;
    }
};