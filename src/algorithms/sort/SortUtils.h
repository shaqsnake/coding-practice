#ifndef SORT_SORTUTILS_H
#define SORT_SORTUTILS_H

#include <iostream>
#include <ctime>
#include <cassert>

namespace SortUtils
{

int *generateRandomArray(int n, int l, int r)
{
    int *arr = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        arr[i] = l + rand() % (r - l + 1);
    }
    return arr;
}

template <typename T>
T *copyArray(T a[], int n)
{
    T *arr = new T[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = a[i];
    }
    return arr;
}

template <typename T>
void printArray(T arr[], int n)
{
    std::cout << "Sorted result: ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return;
}

template <typename T>
bool isSorted(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }

    return true;
}

template <typename T>
void testSort(const std::string &sortName, void (*sort)(T[], int), T arr[], int n)
{
    auto start = clock();
    sort(arr, n);
    auto end = clock();
    std::cout << sortName << ": " << double(end - start) / CLOCKS_PER_SEC << "s" << std::endl;

    assert(isSorted(arr, n));

    return;
}

}; // namespace SortUtils

#endif // SORT_SORTUTILS_H