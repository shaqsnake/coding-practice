#ifndef SORT_INSERTIONSORT_H
#define SORT_INSERTIONSORT_H

namespace MySort
{

template <typename T>
void insertionSort(T a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        T tmp = a[i];
        int j;
        for (j = i; j > 0 && tmp < a[j - 1]; --j)
        {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }

    return;
}

};     // namespace MySort
#endif //SORT_INSERTIONSORT_H