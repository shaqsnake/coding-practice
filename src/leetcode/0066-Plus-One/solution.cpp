class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res;
        int t = 1;
        for (auto rit = digits.rbegin(); rit != digits.rend(); rit++)
        {
            t += *rit;
            res.push_back(t % 10);
            t /= 10;
        }
        if (t)
            res.push_back(t);

        reverse(res.begin(), res.end());
        return res;
    }
};