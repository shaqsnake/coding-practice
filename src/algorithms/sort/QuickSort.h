#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H

namespace MySort
{

template <typename T>
void _quicksort(T a[], int l, int r)
{
    if (l >= r)
        return;

    int p = a[(l + r) >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            ++i;
        while (p > a[i]);
        do
            --j;
        while (p < a[j]);
        if (i < j)
            std::swap(a[i], a[j]);
        else
            break;
    }

    _quicksort(a, l, j), _quicksort(a, j + 1, r);

    return;
}

template <typename T>
void quickSort(T a[], int n)
{
    _quicksort(a, 0, n - 1);
}

}; // namespace MySort

#endif // SORT_QUICKSORT_H