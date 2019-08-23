// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-23 15:00:19
 * @LastEditTime: 2019-08-23 15:19:48
 * @Description: 84. Largest Rectangle in Histogram
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }

        while (stk.size()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, heights[i] * (right[i] - left[i] - 1));

        return res;
    }
};
