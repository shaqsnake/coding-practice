#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;

template<typename T>
vector<T> selectionSort(vector<T> vec)
{
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i)
    {
        decltype(i) min = i;
        for (decltype(i) j = i + 1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        swap(vec[i], vec[min]); // Use stl algothrim swap
    }
    return vec;
}

template<typename T>
void print_vector(vector<T> vec) {
    for (const auto &v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec(10);
    generate(vec.begin(), vec.end(), []() { return rand() % 100; });
    print_vector(selectionSort(vec));

    vector<double> vec2 = {9.9, 8.8, 7.7, 1.1, 4.4, 5.5};
    print_vector(selectionSort(vec2));

    vector<string> vec3 = {"D", "C", "B", "A"};
    print_vector(selectionSort(vec3));

    vector<Student> vec4 = {{"A", 60}, {"B", 55}, {"C", 60}, {"D", 88}};
    print_vector(selectionSort(vec4));
    return 0;
}