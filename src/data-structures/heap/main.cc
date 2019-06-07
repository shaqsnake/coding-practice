#include "Heap.h"
#include <ctime>
#include <iostream>

using namespace std;

int main() {

    MaxHeap<int> heap = MaxHeap<int>(100);
    constexpr int N = 10;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        heap.add(rand() % 100);

    while (!heap.empty())
        cout << heap.pop() << " ";
    cout << endl;
    return 0;
}