// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-23 17:50:27
 * @LastEditTime: 2019-08-23 17:58:17
 * @Description: 918. Maximum Sum Circular Subarray
 */

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n; i++) A.push_back(A[i]);

        vector<int> S(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++) S[i] = S[i-1] + A[i-1];

        deque<int> q;
        q.push_back(0):
        int res = INT_MIN;
        for (int i = 1; i <= 2 * n; i++) {
            if (q.size() && i - q.front() > n) q.pop_front();
            if (q.size()) res = max(res, S[i] - S[q.front()]);
            while (q.size() && S[q.back()] >= S[i]) q.pop_back();
            q.push_back(i);
        }

        return res;
    }
};
