#ifndef SORT_SELECTIONSORT_H
#define SORT_SELECTIONSORT_H

namespace MySort
{

template <typename T>
std::vector<T> selectionSort(std::vector<T> vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        int min = i;
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        std::swap(vec[i], vec[min]); // Use stl algothrim swap
    }
    return vec;
}

};     // namespace MySort
#endif //SORT_SELECTIONSORT_H