#include "Heap.hpp"
#include "IndexHeap.hpp"
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    constexpr int N = 10;
    srand(time(NULL));
    int a[N];
    for (int i = 0; i < N; i++)
        a[i] = rand() % 100;

    auto minHeap = MyHeap<int>(a, N);
    auto maxHeap = MyHeap<int, greater<int>>(a, N);
    minHeap.printHeap();
    while (!minHeap.empty())
        cout << minHeap.pop() << " ";
    cout << endl;

    maxHeap.printHeap();
    while (!maxHeap.empty()) {
        cout << maxHeap.pop() << " ";
    }
    cout << endl;

    auto minIndexHeap = MyIndexHeap<int>(a, N);
    minIndexHeap.update(0, 100);
    minIndexHeap.printHeap();
    cout << a[minIndexHeap.popIndex()] << endl;
    while (minIndexHeap.size())
        cout << minIndexHeap.pop() << " ";
    cout << endl;

    auto maxIndexHeap = MyIndexHeap<int, greater<int>>(a, N);
    maxIndexHeap.update(1, -1);
    maxIndexHeap.printHeap();
    cout << a[maxIndexHeap.popIndex()] << endl;
    while (maxIndexHeap.size())
        cout << maxIndexHeap.pop() << " ";
    cout << endl;
    return 0;
}