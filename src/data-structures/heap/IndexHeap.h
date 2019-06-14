#ifndef _INDEXHEAP_H
#define _INDEXHEAP_H

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>

template <class ElemType, class Compare = std::less<ElemType>>
class MyIndexHeap {
public:
    MyIndexHeap(int capacity);
    MyIndexHeap(ElemType arr[], int capacity);
    ~MyIndexHeap();

    int size() { return size_; }
    bool empty() { return size_ == 0; }

    void add(ElemType x);
    ElemType &peek();
    ElemType pop();
    void update(int i, ElemType x);
    void printHeap();

private:
    ElemType *data_;
    int *idx_;
    int size_;
    int capacity_;
    Compare cmp;

    void siftUp(int i);
    void siftDown(int i);
    void printNode(int i, const std::string &prefix);
};

// Consutructors/Destructors
template <class ElemType, class Compare>
inline MyIndexHeap<ElemType, Compare>::MyIndexHeap(int capacity)
    : data_(new ElemType[capacity + 1]), idx_(new int[capacity]), size_(0),
      capacity_(capacity) {}

template <class ElemType, class Compare>
inline MyIndexHeap<ElemType, Compare>::MyIndexHeap(ElemType arr[], int capacity)
    : data_(new ElemType[capacity + 1]), idx_(new int[capacity + 1]),
      size_(capacity), capacity_(capacity) {
    for (int i = 1; i <= capacity; i++) {
        idx_[i] = i;
        data_[i] = arr[i - 1];
    }

    for (int i = capacity / 2; i >= 1; i--)
        siftDown(i);
}

template <class ElemType, class Compare>
inline MyIndexHeap<ElemType, Compare>::~MyIndexHeap() {
    delete[] data_;
    delete[] idx_;
}

// Public member func
template <class ElemType, class Compare>
void MyIndexHeap<ElemType, Compare>::add(ElemType x) {
    assert(size_ + 1 <= capacity_);
    data_[++size_] = x;
    idx_[size_] = size_;
    siftUp(size_);
}

template <class ElemType, class Compare>
ElemType &MyIndexHeap<ElemType, Compare>::peek() {
    assert(size_ > 0);
    return data_[idx_[1]];
}

template <class ElemType, class Compare>
ElemType MyIndexHeap<ElemType, Compare>::pop() {
    assert(size_ > 0);
    ElemType res = data_[idx_[1]];
    using std::swap;
    swap(idx_[1], idx_[size_--]);
    siftDown(1);
    return res;
}

template <class ElemType, class Compare>
void MyIndexHeap<ElemType, Compare>::update(int i, ElemType x) {
    assert (i + 1 <= size_);
    data_[i+1] = x;

    for (int j = 1; j <= size_; j++)
        if (j == idx_[i+1])
            siftUp(j), siftDown(j);
}

template <class ElemType, class Compare>
void MyIndexHeap<ElemType, Compare>::siftUp(int i) {
    while (i / 2 && cmp(data_[idx_[i]], data_[idx_[i / 2]])) {
        using std::swap;
        swap(idx_[i], idx_[i / 2]);
        i /= 2;
    }
}

template <class ElemType, class Compare>
void MyIndexHeap<ElemType, Compare>::siftDown(int i) {
    int j = i;
    if (2 * i <= size_ && cmp(data_[idx_[2 * i]], data_[idx_[j]]))
        j = 2 * i;
    if (2 * i + 1 <= size_ && cmp(data_[idx_[2 * i + 1]], data_[idx_[j]]))
        j = 2 * i + 1;
    if (j != i) {
        using std::swap;
        swap(idx_[i], idx_[j]);
        siftDown(j);
    }
}

template <class ElemType, class Compare>
void MyIndexHeap<ElemType, Compare>::printHeap() {
    printNode(1, "");
}

template <class ElemType, class Compare>
void MyIndexHeap<ElemType, Compare>::printNode(int i,
                                               const std::string &prefix) {
    bool isLeft = true;
    if (i == size_ || i & 1)
        isLeft = false;

    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    if (i <= size_)
        std::cout << data_[idx_[i]];
    std::cout << std::endl;

    if (2 * i <= size_)
        printNode(2 * i, prefix + (isLeft ? "│   " : "    "));
    if (2 * i + 1 <= size_)
        printNode(2 * i + 1, prefix + (isLeft ? "│   " : "    "));
}

#endif // _INDEX_HEAP_H