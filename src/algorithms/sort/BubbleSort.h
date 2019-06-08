#ifndef SORT_BUBBLESORT_H
#define SORT_BUBBLESORT_H

#include <algorithm>

namespace MySort {

template <typename T> void bubbleSort(T a[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[i])
                std::swap(a[i], a[j]);
        }
    }
    return;
}

template <typename T> void bubbleSort2(T a[], int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                std::swap(a[i], a[i - 1]);
                swapped = true;
            }
        }
    } while (swapped);

    return;
}

};     // namespace MySort
#endif // SORT_BUBBLESORT_H