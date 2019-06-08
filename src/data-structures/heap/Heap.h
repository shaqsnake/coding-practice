#ifndef _HEAP_H
#define _HEAP_H

#include <algorithm>
#include <functional>
#include <iostream>

template <class ElemType, class Compare = std::less<ElemType>> class MyHeap {
public:
    MyHeap(int capacity)
        : data_(new ElemType[capacity + 1]), size_(0), capacity_(capacity) {}
    MyHeap(ElemType arr[], int capacity);
    ~MyHeap() { delete[] data_; }

    int size() { return size_; }
    bool empty() { return size_ == 0; }

    void add(ElemType x);
    ElemType peek();
    ElemType pop();
    void printHeap();

private:
    ElemType *data_;
    int size_;
    int capacity_;
    Compare cmp;

    void siftUp(int i);
    void siftDown(int i);
    void printNode(int i, const std::string &prefix);
};

template <class ElemType, class Compare>
MyHeap<ElemType, Compare>::MyHeap(ElemType arr[], int capacity)
    : data_(new ElemType[capacity + 1]), size_(capacity), capacity_(capacity) {
    for (int i = 1; i <= capacity; i++)
        data_[i] = arr[i - 1];

    for (int i = capacity / 2; i >= 1; i--)
        siftDown(i);
}

template <class ElemType, class Compare>
void MyHeap<ElemType, Compare>::add(ElemType x) {
    assert(size_ + 1 <= capacity_);
    data_[++size_] = x;
    siftUp(size_);
}

template <class ElemType, class Compare>
ElemType MyHeap<ElemType, Compare>::peek() {
    assert(size_ > 0);
    return data_[1];
}

template <class ElemType, class Compare>
ElemType MyHeap<ElemType, Compare>::pop() {
    assert(size_ > 0);
    ElemType res = data_[1];
    std::swap(data_[1], data_[size_--]);
    siftDown(1);

    return res;
}

template <class ElemType, class Compare>
void MyHeap<ElemType, Compare>::siftUp(int i) {
    while (cmp(i / 2 && data_[i], data_[i / 2])) {
        std::swap(data_[i / 2], data_[i]);
        i /= 2;
    }
}

template <class ElemType, class Compare>
void MyHeap<ElemType, Compare>::siftDown(int i) {
    int j = i;
    if (2 * i <= size_ && cmp(data_[2 * i], data_[j]))
        j = 2 * i;
    if (2 * i + 1 <= size_ && cmp(data_[2 * i + 1], data_[j]))
        j = 2 * i + 1;
    if (j != i) {
        std::swap(data_[i], data_[j]);
        siftDown(j);
    }
}

template <class ElemType, class Compare>
void MyHeap<ElemType, Compare>::printHeap() {
    printNode(1, "");
}

template <class ElemType, class Compare>
void MyHeap<ElemType, Compare>::printNode(int i, const std::string &prefix) {
    bool isLeft = true;
    if (i == size_ || i & 1)
        isLeft = false;

    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    std::cout << data_[i] << std::endl;

    if (2 * i <= size_)
        printNode(2 * i, prefix + (isLeft ? "│   " : "    "));
    if (2 * i + 1 <= size_)
        printNode(2 * i + 1, prefix + (isLeft ? "│   " : "    "));
}

#endif // _HEAP_H