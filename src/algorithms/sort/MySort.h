#ifndef SORT_MYSORT_H
#define SORT_MYSORT_H

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
#endif //SORT_MYSORT_H