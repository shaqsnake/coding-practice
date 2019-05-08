#ifndef SORT_INSERTIONSORT_H
#define SORT_INSERTIONSORT_H

namespace MySort
{

template <typename T>
std::vector<T> insertionSort(std::vector<T> vec)
{
    for (int i = 1; i < vec.size(); ++i)
    {
        T tmp = vec[i];
        int j;
        for (j = i; j > 0 && tmp < vec[j - 1]; --j)
        {
            vec[j] = vec[j - 1];
        }
        vec[j] = tmp;
    }

    return vec;
}

};     // namespace MySort
#endif //SORT_INSERTIONSORT_H