#include <iostream>
#include <algorithm>
#include "SortUtils.h"
#include "Student.h"

using namespace std;

template <typename T>
void insertionSort(vector<T> &vec)
{
    for (auto it = vec.begin() + 1; it != vec.end(); ++it)
    {
        for (auto jt = it; jt != vec.begin() && *jt < *(jt - 1); --jt)
        {
            swap(*jt, *(jt - 1));
        }
    }

    return;
}

int main()
{
    vector<int> vec(100);
    generate(vec.begin(), vec.end(), []() { return rand() % 100; });
    cout << SortUtils::isSorted(vec) << endl;
    insertionSort(vec);
    cout << SortUtils::isSorted(vec) << endl;
    SortUtils::printVector(vec);
    SortUtils::testSort("Insertion Sort", insertionSort, vec);

    vector<double> vec2 = {9.9, 8.8, 7.7, 1.1, 4.4, 5.5};
    insertionSort(vec2);
    SortUtils::printVector(vec2);

    vector<string> vec3 = {"D", "C", "B", "A"};
    insertionSort(vec3);
    SortUtils::printVector(vec3);

    vector<Student> vec4 = {{"A", 60}, {"B", 55}, {"C", 60}, {"D", 88}};
    insertionSort(vec4);
    SortUtils::printVector(vec4);
    return 0;
}