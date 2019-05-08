#include <vector>
#include <algorithm>
#include "SortUtils.h"
#include "Student.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"

using namespace std;

int main()
{
    constexpr int n = 10000;
    vector<int> vec(n);
    generate(vec.begin(), vec.end(), []() { return rand() % n; });
    SortUtils::testSort("Selection Sort", MySort::selectionSort, vec);
    SortUtils::testSort("Insertion Sort", MySort::insertionSort, vec);
    SortUtils::testSort("Bubble Sort", MySort::bubbleSort, vec);
    SortUtils::testSort("Bubble Sort 2", MySort::bubbleSort2, vec);

    vector<double> vec2 = {9.9, 8.8, 7.7, 1.1, 4.4, 5.5};
    SortUtils::printVector(MySort::selectionSort(vec2));
    SortUtils::printVector(MySort::insertionSort(vec2));
    SortUtils::printVector(MySort::bubbleSort(vec2));
    SortUtils::printVector(MySort::bubbleSort2(vec2));

    vector<string> vec3 = {"D", "C", "B", "A"};
    SortUtils::printVector(MySort::selectionSort(vec3));
    SortUtils::printVector(MySort::insertionSort(vec3));
    SortUtils::printVector(MySort::bubbleSort(vec3));
    SortUtils::printVector(MySort::bubbleSort2(vec3));

    vector<Student> vec4 = {{"A", 60}, {"B", 55}, {"C", 60}, {"D", 88}};
    SortUtils::printVector(MySort::selectionSort(vec4));
    SortUtils::printVector(MySort::insertionSort(vec4));
    SortUtils::printVector(MySort::bubbleSort(vec4));
    SortUtils::printVector(MySort::bubbleSort2(vec4));

    return 0;
}