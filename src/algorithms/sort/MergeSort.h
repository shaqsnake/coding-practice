#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

#include <vector>

namespace MySort
{

template <typename T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right)
{
    std::vector<T> res;
    auto l_begin = left.begin(), r_begin = right.begin();
    while (l_begin != left.end() && r_begin != right.end())
    {
        if (*l_begin < *r_begin)
        {
            res.push_back(*l_begin++);
        }
        else
        {
            res.push_back(*r_begin++);
        }
    }

    while (l_begin != left.end())
    {
        res.push_back(*l_begin++);
    }
    while (r_begin != right.end())
    {
        res.push_back(*r_begin++);
    }

    return res;
}

template <typename T>
std::vector<T> mergeSort(std::vector<T> vec)
{
    auto begin = vec.begin(), end = vec.end();
    if (vec.size() == 1)
    {
        return vec;
    }
    auto mid = begin + vec.size() / 2;
    std::vector<T> l = mergeSort(std::vector<T>(begin, mid));
    std::vector<T> r = mergeSort(std::vector<T>(mid, end));
    if (r.front() < l.back()) {
        return merge(l, r);
    } else {
        l.insert(l.end(), r.begin(), r.end());
        return l; 
    }
}

}; // namespace MySort

#endif // SORT_MERGESORT_H