class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return bsearch(nums, 0, nums.size() - 1, target);
    }

private:
    vector<int> bsearch(vector<int> &a, int left, int right, int target)
    {
        vector<int> res{-1, -1};
        if (a.empty())
            return res;

        int l = left, r = right;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] == target)
            res[0] = l;

        l = left, r = right;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (a[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        if (a[l] == target)
            res[1] = l;

        return res;
    }
};