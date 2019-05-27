class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int l = -1, r = -1;
        for (const auto &interval : intervals)
        {
            if (r < interval[0])
            {
                if (l != -1)
                    res.push_back({l, r});
                l = interval[0], r = interval[1];
            }
            else
            {
                l = min(l, interval[0]);
                r = max(r, interval[1]);
                cout << l << r << endl;
            }
        }
        if (l != -1)
            res.push_back({l, r});
        return res;
    }
};