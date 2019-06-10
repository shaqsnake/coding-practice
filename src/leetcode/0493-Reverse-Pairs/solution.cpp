class Solution {
public:
    int reversePairs(vector<int> &nums) {
        return mergeCount(nums, 0, nums.size() - 1);
    }

private:
    int mergeCount(vector<int> &a, int l, int r) {
        if (l >= r)
            return 0;

        int mid = l + r >> 1;
        int res = mergeCount(a, l, mid) + mergeCount(a, mid + 1, r);

        // Count the num of revers pair.
        for (int i = l, j = mid + 1; i <= mid; i++) {
            while (j <= r && a[i] > 2ll * a[j])
                j++;
            res += j - (mid + 1);
        }

        int i = l, j = mid + 1, k = 0, tmp[r - l + 1];
        while (i <= mid && j <= r) {
            if (a[i] <= a[j])
                tmp[k++] = a[i++];
            else
                tmp[k++] = a[j++];
        }
        while (i <= mid)
            tmp[k++] = a[i++];
        while (j <= r)
            tmp[k++] = a[j++];

        for (int i = l, j = 0; i <= r; i++, j++)
            a[i] = tmp[j];

        return res;
    }
};