#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

namespace MySort
{

template <typename T>
void _mergesort(T arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    _mergesort(arr, l, mid);
    _mergesort(arr, mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    T tmp[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];

    for (int i = l, j = 0; i <= r; ++i, ++j)
        arr[i] = tmp[j];
}

template <typename T>
void mergeSort(T arr[], int n)
{
    _mergesort(arr, 0, n - 1);
}

}; // namespace MySort

#endif // SORT_MERGESORT_H