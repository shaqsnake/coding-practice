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
};