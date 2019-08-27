// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-27 15:03:14
 * @LastEditTime: 2019-08-27 15:16:19
 * @Description: 692. Top K Frequent Words
 */

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        priority_queue<pair<int, string>> heap;

        for (const auto &w : words) map[w]++;

        for (const auto &m : map) {
            heap.push(make_pair(-m.second, m.first));
            if (heap.size() > k) heap.pop();
        }

        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = heap.top().second;
            heap.pop();
        }

        return res;
    }
};
