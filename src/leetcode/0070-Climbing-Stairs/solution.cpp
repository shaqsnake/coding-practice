class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) return n;

        int res1, res2;
        if (lru.find(n-1) == lru.end()) {
            res1 = climbStairs(n-1);
            lru.insert({n-1, res1});
        } else {
            res1 = lru[n-1];
        }

        if (lru.find(n-2) == lru.end()) {
            res2 = climbStairs(n-2);
            lru.insert({n-2, res2});
        } else {
            res2 = lru[n-2];
        }

        return res1 + res2;
    }

private:
    map<int, int> lru;
};