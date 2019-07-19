// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-06-24 16:01:12
 * @LastEditTime: 2019-07-19 17:40:43
 * @Description:
 */
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        bool not_prime[n + 10] = {n + 10, false};
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (not_prime[i])
                continue;
            res++;
            for (int j = i; j < n; j += i)
                not_prime[j] = true;
        }

        return res;
    }

    int countPrimes2(int n) {

        bool st[n + 10] = {false, n + 10};
        int primes[n + 10];
        int idx = 0;

        for (int i = 2; i < n; i++) {
            if (!st[i])
                primes[idx++] = i;
            for (int j = 0; primes[j] <= n / i; j++) {
                st[primes[j] * i] = true;
                if (i % primes[j] == 0)
                    break;
            }
        }

        return idx;
    }
};