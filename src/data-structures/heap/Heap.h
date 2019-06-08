#ifndef _HEAP_H
#define _HEAP_H

#include <algorithm>
#include <iostream>

template <typename T> class MaxHeap {
public:
    MaxHeap(int capacity)
        : data_(new T[capacity + 1]), size_(0), capacity_(capacity) {}

    ~MaxHeap() { delete[] data_; }

    int size() { return size_; }
    bool empty() { return size_ == 0; }

    void add(T x);
    T peek();
    T pop();
    void printHeap();

private:
    T *data_;
    int size_;
    int capacity_;

    void siftUp(int i);
    void siftDown(int i);
    void printNode(int i, const std::string &prefix);
};

template <typename T> void MaxHeap<T>::add(T x) {
    assert(size_ + 1 <= capacity_);
    data_[++size_] = x;
    siftUp(size_);
}

template <typename T> T MaxHeap<T>::peek() {
    assert(size_ > 0);
    return data_[1];
}

template <typename T> T MaxHeap<T>::pop() {
    assert(size_ > 0);
    T res = data_[1];
    std::swap(data_[1], data_[size_--]);
    siftDown(1);

    return res;
}

template <typename T> void MaxHeap<T>::siftUp(int i) {
    while (i / 2 && data_[i / 2] < data_[i]) {
        std::swap(data_[i / 2], data_[i]);
        i /= 2;
    }
}

template <typename T> void MaxHeap<T>::siftDown(int i) {
    int max = i;
    if (2 * i <= size_ && data_[2 * i] > data_[max])
        max = 2 * i;
    if (2 * i + 1 <= size_ && data_[2 * i + 1] > data_[max])
        max = 2 * i + 1;
    if (max != i) {
        std::swap(data_[i], data_[max]);
        siftDown(max);
    }
}

template <typename T> void MaxHeap<T>::printHeap() { printNode(1, ""); }

template <typename T>
void MaxHeap<T>::printNode(int i, const std::string &prefix) {
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