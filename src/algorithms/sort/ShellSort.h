#ifndef SORT_SHELLSORT_H
#define SORT_SHELLSORT_H

namespace MySort
{

/*
 * Shellsort is a generalization of insertion sort 
 * that allows the exchange of items that are far apart.
 */
template <typename T>
void shellSort(T a[], int n)
{
    int step = 1, factor = 4;

    // step = 1 at last loop
    while (step < n / factor)
    {
        step = factor * step + 1;
    }

    while (step > 0)
    {
        // The logic is similar to insertion sort, 
        // only the step should scale down at each loop.
        for (int i = step; i < n; i += step)
        {
            int j;
            T tmp = a[i];
            for (j = i; j >= step && tmp < a[j - step]; j -= step)
            {
                a[j] = a[j - step];
            }
            a[j] = tmp;
        }
        step /= factor;
    }

    return;
}

}; // namespace MySort

#endif // SORT_SHELLSORT_H