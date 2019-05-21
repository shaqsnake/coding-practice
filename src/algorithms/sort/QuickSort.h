#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H

namespace MySort
{

template <typename T>
void _quicksort(T a[], int l, int r)
{
    if (l >= r)
        return;

    // int p = a[(l + r) >> 1]
    int p = a[rand() % (r - l + 1) + l]; // random pivot
    int i = l - 1, j = r + 1;

    // two-ways quick sort
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
    srand(time(NULL));
    _quicksort(a, 0, n - 1);
}

template <typename T>
void _quicksort3w(T a[], int l, int r)
{
    if (l >= r)
        return;

    std::swap(a[l], a[rand() % (r - l + 1) + l]);
    T p = a[l];

    int lt = l;     // a[l+1, lt] < p
    int gt = r + 1; // a[gt, r] > p
    int i = l + 1;  // a[lt+1, i) == p
    while (i < gt)
    {
        if (a[i] < p)
            std::swap(a[++lt], a[i++]);
        else if (a[i] > p)
            std::swap(a[i], a[--gt]);
        else
            ++i;
    }
    std::swap(a[l], a[lt]);

    _quicksort3w(a, l, lt - 1);
    _quicksort3w(a, gt, r);

    return;
}

template <typename T>
void quickSort3Ways(T a[], int n)
{
    srand(time(NULL));
    _quicksort3w(a, 0, n - 1);
}

};     // namespace MySort
#endif // SORT_QUICKSORT_H