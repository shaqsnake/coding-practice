#include "Heap.h"
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    constexpr int N = 10;
    srand(time(NULL));
    int a[N];
    for (int i = 0; i < N; i++)
        a[i] = rand() % 100;
    MyHeap<int> heap = MyHeap<int>(a, N);

    heap.printHeap();

    cout << heap.peek() << endl;

    while (!heap.empty())
        cout << heap.pop() << " ";
    cout << endl;
    return 0;
}