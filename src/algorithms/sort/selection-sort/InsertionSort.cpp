#include <iostream>
#include <algorithm>
#include "SortUtils.h"

using namespace std;

template<typename T>
void insertionSort(vector<T> &vec) {
    for (auto it = vec.begin() + 1; it != vec.end(); ++it) {
        for (auto jt = it; jt != vec.begin() && *jt < *(jt-1); --jt) {
            swap(*jt, *(jt-1));
        }
    }

    return;
}

int main() {
    vector<int> vec(100);
    generate(vec.begin(), vec.end(), []() { return rand() % 100; });
    insertionSort(vec);
    SortUtils::printVector(vec);
    SortUtils::testSort("Insertion Sort", insertionSort, vec);
}