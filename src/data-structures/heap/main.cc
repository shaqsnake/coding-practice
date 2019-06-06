#include <iostream>
#include "Heap.h"

using namespace std;

int main() {

    MaxHeap<int> heap = MaxHeap<int>(100);
    cout << heap.size() << endl;
    cout << heap.empty() << endl;
    return 0;
}