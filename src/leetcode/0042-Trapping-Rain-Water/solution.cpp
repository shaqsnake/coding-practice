// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-23 16:22:57
 * @LastEditTime: 2019-08-23 16:30:01
 * @Description: 42. Trapping Rain Water
 */

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;

        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            int last = 0;
            while (stk.size() && height[stk.top()] <= height[i]) {
                int t = stk.top();
                stk.pop();
                res += (i - t - 1) * (height[t] - last);
                last = height[t];
            }

            if (stk.size()) res += (i - stk.top() - 1) * (height[i] - last);
            stk.push(i);
        }

        return res;
    }
};
