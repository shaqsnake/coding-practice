class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickFind(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }

private:
    int quickFind(vector<int> &a, int l, int r, int k)
    {
        if (l >= r)
            return a[l];

        int p = a[l + r >> 1], i = l - 1, j = r + 1;
        while (i < j)
        {
            do
                i++;
            while (a[i] < p);
            do
                j--;
            while (a[j] > p);
            if (i < j)
                swap(a[i], a[j]);
        }

        int sl = j - l + 1;
        if (sl >= k)
            return quickFind(a, l, j, k);
        return quickFind(a, j + 1, r, k - sl);
    }
};