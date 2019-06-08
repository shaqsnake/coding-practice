#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

#include "../../data-structures/heap/Heap.h"

namespace MySort {

template <typename T> void heapSort(T arr[], int n) {
    MyHeap<T> heap = MyHeap<T>(arr, n);
    for (int i = 0; i < n; i++)
        arr[i] = heap.pop();
}
};     // namespace MySort
#endif // SORT_HEAPSORT_H