#ifndef SORT_SHELLSORT_H
#define SORT_SHELLSORT_H

namespace MySort
{

/*
 * Shellsort is a generalization of insertion sort 
 * that allows the exchange of items that are far apart.
 */
template <typename T>
std::vector<T> shellSort(std::vector<T> vec)
{
    int step = 1, factor = 4;

    // step = 1 at last loop
    while (step < vec.size() / factor)
    {
        step = factor * step + 1;
    }

    while (step > 0)
    {
        // The logic is similar to insertion sort, 
        // only the step should scale down at each loop.
        for (int i = step; i < vec.size(); i += step)
        {
            int j;
            T temp = vec[i];
            for (j = i; j >= step && temp < vec[j - step]; j -= step)
            {
                vec[j] = vec[j - step];
            }
            vec[j] = temp;
        }
        step /= factor;
    }

    return vec;
}

}; // namespace MySort

#endif // SORT_SHELLSORT_H