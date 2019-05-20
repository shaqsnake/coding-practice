#ifndef SORT_SELECTIONSORT_H
#define SORT_SELECTIONSORT_H

namespace MySort
{

template <typename T>
void selectionSort(T a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        std::swap(a[i], a[min]); // Use stl algothrim swap
    }
    return;
}

};     // namespace MySort
#endif //SORT_SELECTIONSORT_H