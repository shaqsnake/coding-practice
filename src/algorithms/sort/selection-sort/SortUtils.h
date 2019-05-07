#ifndef SELECTION_SORT_SORT_UTILS_H
#define SELECTION_SORT_SORT_UTILS_H

#include <vector>
#include <string>
#include <ctime>
#include <cassert>

namespace SortUtils
{

template <typename T>
void printVector(std::vector<T> &vec)
{
    std::cout << "Sorted result: ";
    for (const auto &v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return;
}

template <typename T>
bool isSorted(std::vector<T> vec)
{
    for (auto i = 0; i < vec.size(); ++i)
    {
        if (vec[i] < vec[i - 1])
        {
            return false;
        }
    }

    return true;
}

template <typename T>
void testSort(const std::string &sortName, void (*sort)(std::vector<T> &), std::vector<T> &vec)
{
    auto start = clock();
    sort(vec);
    auto end = clock();
    std::cout << sortName << ": " << double(end - start) / CLOCKS_PER_SEC << "s" << std::endl;

    assert(isSorted(vec));

    return;
}

}; // namespace SortUtils

#endif // SELECTION_SORT_SORT_UTILS_H