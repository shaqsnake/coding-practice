// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-28 10:14:40
 * @LastEditTime: 2019-08-28 11:41:25
 * @Description: 352. Data Stream as Disjoint Intervals
 */

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = L.lower_bound(val);
        if (it != L.end() && it->second <= val) return;

        int left = L.count(val - 1), right = R.count(val + 1);
        if (left && right) {
            L[R[val + 1]] = L[val - 1];
            R[L[val - 1]] = R[val + 1];
            L.erase(val - 1), R.erase(val + 1);

        } else if (left) {
            L[val] = L[val - 1];
            R[L[val-1]] = val;
            L.erase(val - 1);

        } else if (right) {
            R[val] = R[val + 1];
            L[R[val + 1]] = val;
            R.erase(val + 1); 

        } else {
            L[val] = R[val] = val;
            
        }

    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (const auto &r : R) res.push_back({r.first, r.second});
        
        return res;
    }

private:
    map<int, int> L, R;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
