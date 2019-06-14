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
    bool contain(int i) { 
        assert (i + 1 >= 1 && i + 1 <= size_);
        return rev_[i+1] != 0;}

    void add(ElemType x);
    ElemType &peek();
    ElemType pop();
    int popIndex();
    void update(int i, ElemType x);
    void printHeap();

private:
    ElemType *data_;
    int *idx_; // index of Heap
    int *rev_; // reversed index
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
    : data_(new ElemType[capacity + 1]), idx_(new int[capacity + 1]),
      rev_(new int[capacity + 1]), size_(0), capacity_(capacity) {}

template <class ElemType, class Compare>
inline MyIndexHeap<ElemType, Compare>::MyIndexHeap(ElemType arr[], int capacity)
    : data_(new ElemType[capacity + 1]), idx_(new int[capacity + 1]),
      rev_(new int[capacity + 1]), size_(capacity), capacity_(capacity) {
    for (int i = 1; i <= capacity; i++) {
        idx_[i] = i;
        rev_[i] = i;
        data_[i] = arr[i - 1];
    }

    for (int i = capacity / 2; i >= 1; i--)
        siftDown(i);
}

template <class ElemType, class Compare>
inline MyIndexHeap<ElemType, Compare>::~MyIndexHeap() {
    delete[] data_;
    delete[] idx_;
    delete[] rev_;
}

// Public member func
template <class ElemType, class Compare>
void MyIndexHeap<ElemType, Compare>::add(ElemType x) {
    assert(size_ + 1 <= capacity_);
    data_[++size_] = x;
    idx_[size_] = size_;
    rev_[size_] = size_;
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
    swap(idx_[1], idx_[size_]);
    rev_[idx_[size_]] = 0;
    size_--;

    if (size_) {
        rev_[idx_[1]] = 1;
        siftDown(1);
    }
    return res;
}

template <class ElemType, class Compare>
int MyIndexHeap<ElemType, Compare>::popIndex() {
    assert(size_ > 0);
    return idx_[1] - 1;
}

template <class ElemType, class Compare>
void MyIndexHeap<ElemType, Compare>::update(int i, ElemType x) {
    assert(contain(i));
    data_[++i] = x;
    siftUp(rev_[i]);
    siftDown(rev_[i]);
}

template <class ElemType, class Compare>
void MyIndexHeap<ElemType, Compare>::siftUp(int i) {
    while (i / 2 && cmp(data_[idx_[i]], data_[idx_[i / 2]])) {
        using std::swap;
        swap(idx_[i], idx_[i / 2]);
        swap(rev_[idx_[i]], rev_[idx_[i / 2]]);
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
        swap(rev_[idx_[i]], rev_[idx_[j]]);
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