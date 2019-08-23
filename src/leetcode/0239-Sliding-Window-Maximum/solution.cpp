// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-23 17:05:48
 * @LastEditTime: 2019-08-23 17:12:16
 * @Description: 239. Sliding Window Maximum
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            if (dq.size() && i - dq.front() + 1 > k) dq.pop_front();
            while (dq.size() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};
