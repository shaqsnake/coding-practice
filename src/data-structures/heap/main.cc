#include "Heap.h"
#include <ctime>
#include <iostream>

using namespace std;

int main() {

    MaxHeap<int> heap = MaxHeap<int>(100);
    constexpr int N = 100;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        heap.add(rand() % 100);

    heap.printHeap();

    cout << heap.peek() << endl;

    while (!heap.empty())
        cout << heap.pop() << " ";
    cout << endl;
    return 0;
}