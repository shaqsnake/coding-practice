#ifndef SORT_BUBBLESORT_H
#define SORT_BUBBLESORT_H

namespace MySort
{

template <typename T>
std::vector<T> bubbleSort(std::vector<T> vec)
{
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i)
    {
        for (auto j = 0; j < vec.size() - i - 1; ++j)
        {
            if (vec[j + 1] < vec[j])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }

    return vec;
}

template <typename T>
std::vector<T> bubbleSort2(std::vector<T> vec)
{
    bool swapped;
    do
    {
        swapped = false;
        for (decltype(vec.size()) i = 1; i < vec.size(); ++i)
        {
            if (vec[i] < vec[i - 1])
            {
                std::swap(vec[i], vec[i - 1]);
                swapped = true;
            }
        }
    } while (swapped);

    return vec;
}

};     // namespace MySort
#endif //SORT_BUBBLESORT_H