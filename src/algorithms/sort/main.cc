// #include <algorithm>
#include "BubbleSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "SortUtils.h"
#include "Student.h"

using namespace std;

int main() {
    constexpr int n = 1000000;
    cout << "Test for random array, size = " << n << ", random range [0, "
         << n - 1 << "]" << endl;
    int *iarr = SortUtils::generateRandomArray(n, 0, n - 1);
    int *iarr1 = SortUtils::copyArray(iarr, n);
    int *iarr2 = SortUtils::copyArray(iarr, n);
    int *iarr3 = SortUtils::copyArray(iarr, n);
    int *iarr4 = SortUtils::copyArray(iarr, n);
    int *iarr5 = SortUtils::copyArray(iarr, n);
    int *iarr6 = SortUtils::copyArray(iarr, n);
    int *iarr7 = SortUtils::copyArray(iarr, n);
    int *iarr8 = SortUtils::copyArray(iarr, n);
    int *iarr9 = SortUtils::copyArray(iarr, n);

    // SortUtils::testSort("Selection Sort", MySort::selectionSort, iarr, n);
    // SortUtils::testSort("Insertion Sort", MySort::insertionSort, iarr1, n);
    // SortUtils::testSort("Bubble Sort", MySort::bubbleSort, iarr2, n);
    // SortUtils::testSort("Bubble Sort 2", MySort::bubbleSort2, iarr3, n);
    // SortUtils::testSort("Shell Sort", MySort::shellSort, iarr4, n);
    SortUtils::testSort("Merge Sort", MySort::mergeSort, iarr5, n);
    SortUtils::testSort("Merge Sort BottomUp", MySort::mergeSort, iarr6, n);
    SortUtils::testSort("Quick Sort", MySort::quickSort, iarr7, n);
    SortUtils::testSort("Quick Sort 3-Ways", MySort::quickSort3Ways, iarr8, n);
    SortUtils::testSort("Heap Sort", MySort::heapSort, iarr9, n);
    cout << endl;

    constexpr int swapTimes = 100;
    cout << "Test for nearly ordered array, size = " << n
         << ", swap time = " << swapTimes << endl;
    int *oarr = SortUtils::generateNearlyOrderedArray(n, swapTimes);
    int *oarr1 = SortUtils::copyArray(oarr, n);
    int *oarr2 = SortUtils::copyArray(oarr, n);
    int *oarr3 = SortUtils::copyArray(oarr, n);
    int *oarr4 = SortUtils::copyArray(oarr, n);
    SortUtils::testSort("Merge Sort", MySort::mergeSort, oarr, n);
    SortUtils::testSort("Merge Sort BottomUp", MySort::mergeSort, oarr1, n);
    SortUtils::testSort("Quick Sort", MySort::quickSort, oarr2, n);
    SortUtils::testSort("Quick Sort 3-Ways", MySort::quickSort3Ways, oarr3, n);
    SortUtils::testSort("Heap Sort", MySort::heapSort, oarr4, n);
    cout << endl;

    cout << "Test for random array with many duplication, size = " << n
         << ", random range [0, 9]" << endl;
    int *duarr = SortUtils::generateRandomArray(n, 0, 9);
    int *duarr1 = SortUtils::copyArray(duarr, n);
    int *duarr2 = SortUtils::copyArray(duarr, n);
    int *duarr3 = SortUtils::copyArray(duarr, n);
    int *duarr4 = SortUtils::copyArray(duarr, n);
    SortUtils::testSort("Merge Sort", MySort::mergeSort, duarr, n);
    SortUtils::testSort("Merge Sort BottomUp", MySort::mergeSort, duarr1, n);
    SortUtils::testSort("Quick Sort", MySort::quickSort, duarr2, n);
    SortUtils::testSort("Quick Sort 3-Ways", MySort::quickSort3Ways, duarr3, n);
    SortUtils::testSort("Heap Sort", MySort::heapSort, duarr4, n);
    cout << endl;

    double darr[10] = {9.9, 8.8, 7.7, 1.1, 4.4, 5.5, 2.2, 6.6, 0.0, 3.3};
    double *darr1 = SortUtils::copyArray(darr, 10);
    double *darr2 = SortUtils::copyArray(darr, 10);
    double *darr3 = SortUtils::copyArray(darr, 10);
    MySort::bubbleSort(darr, 10);
    SortUtils::printArray(darr, 10);
    MySort::mergeSort(darr1, 10);
    SortUtils::printArray(darr1, 10);
    MySort::quickSort3Ways(darr2, 10);
    SortUtils::printArray(darr2, 10);
    MySort::heapSort(darr3, 10);
    SortUtils::printArray(darr3, 10);
    cout << endl;

    string sarr[4] = {"D", "C", "B", "A"};
    string *sarr1 = SortUtils::copyArray(sarr, 4);
    string *sarr2 = SortUtils::copyArray(sarr, 4);
    MySort::bubbleSort(sarr, 4);
    SortUtils::printArray(sarr, 4);
    MySort::mergeSort(sarr1, 4);
    SortUtils::printArray(sarr1, 4);
    MySort::heapSort(sarr2, 4);
    SortUtils::printArray(sarr2, 4);
    cout << endl;

    Student carr[4] = {{"A", 60}, {"B", 55}, {"C", 60}, {"D", 88}};
    Student *carr1 = SortUtils::copyArray(carr, 4);
    MySort::mergeSort(carr, 4);
    SortUtils::printArray(carr, 4);
    MySort::indexHeapSort(carr1, 4);
    SortUtils::printArray(carr1, 4);
    cout << endl;

    return 0;
}