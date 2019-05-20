#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

namespace MySort
{

template <typename T>
void _merge(T a[], int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0;
    T tmp[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];

    for (int i = l, j = 0; i <= r; ++i, ++j)
        a[i] = tmp[j];

    return;
}

template <typename T>
void _mergesort(T a[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    _mergesort(a, l, mid);
    _mergesort(a, mid + 1, r);

    if (a[mid + 1] < a[mid])
        _merge(a, l, mid, r);
}

template <typename T>
void mergeSort(T a[], int n)
{
    _mergesort(a, 0, n - 1);
}

template <typename T>
void mergeSortBU(T a[], int n)
{
    for (int sz = 1; sz < n; sz += sz)
    {
        for (int i = 0; i + sz < n; i += sz + sz)
        {
            _merge(a, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1)); // merge[l, mid] [mid+1, r]
        }
    }
    return;
}

}; // namespace MySort

#endif // SORT_MERGESORT_H