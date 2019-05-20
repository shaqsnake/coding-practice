// #include <algorithm>
#include "SortUtils.h"
#include "Student.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main()
{
    constexpr int n = 100000;
    int *iarr = SortUtils::generateRandomArray(n, 0, n - 1);
    int *iarr1 = SortUtils::copyArray(iarr, n);
    int *iarr2 = SortUtils::copyArray(iarr, n);
    int *iarr3 = SortUtils::copyArray(iarr, n);
    int *iarr4 = SortUtils::copyArray(iarr, n);
    int *iarr5 = SortUtils::copyArray(iarr, n);
    int *iarr6 = SortUtils::copyArray(iarr, n);

    SortUtils::testSort("Selection Sort", MySort::selectionSort, iarr, n);
    SortUtils::testSort("Insertion Sort", MySort::insertionSort, iarr1, n);
    // SortUtils::testSort("Bubble Sort", MySort::bubbleSort, iarr2, n);
    // SortUtils::testSort("Bubble Sort 2", MySort::bubbleSort2, iarr3, n);
    SortUtils::testSort("Shell Sort", MySort::shellSort, iarr4, n);
    SortUtils::testSort("Merge Sort", MySort::mergeSort, iarr5, n);
    SortUtils::testSort("Quick Sort", MySort::quickSort, iarr6, n);

    double darr[10] = {9.9, 8.8, 7.7, 1.1, 4.4, 5.5, 2.2, 6.6, 0.0, 3.3};
    double *darr1 = SortUtils::copyArray(darr, 10);
    MySort::bubbleSort(darr, 10);
    MySort::mergeSort(darr1, 10);
    SortUtils::printArray(darr, 10);
    SortUtils::printArray(darr1, 10);

    string sarr[4] = {"D", "C", "B", "A"};
    string *sarr1 = SortUtils::copyArray(sarr, 4);
    MySort::bubbleSort(sarr, 4);
    SortUtils::printArray(sarr, 4);
    MySort::mergeSort(sarr1, 4);
    SortUtils::printArray(sarr1, 4);

    Student carr[4] = {{"A", 60}, {"B", 55}, {"C", 60}, {"D", 88}};
    MySort::mergeSort(carr, 4);
    SortUtils::printArray(carr, 4);

    return 0;
}