#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// void swap(int &i, int &j) {
//     int temp = i;
//     i = j;
//     j = temp;
// }

vector<int> selectionSort(vector<int> vec) {
    for (decltype(vec.size()) i = 0; i < vec.size(); i++) {
        for (decltype(i) j = i; j < vec.size(); j++) {
            if (vec[i] > vec[j]) {
                swap(vec[i], vec[j]); // Use stl algothrim swap
            }
        }
    }
    return vec;
}

int main() {
    vector<int> vec(10);
    generate(vec.begin(), vec.end(), []() { return rand() % 100;});
    for (const auto &v : selectionSort(vec)) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}