#ifndef _HEAP_H
#define _HEAP_H

#include <algorithm>

template <typename T> class MaxHeap {
public:
    MaxHeap(int capacity) : data_(new T[capacity + 1]), size_(0), idx_(1) {}

    ~MaxHeap() { delete[] data_; }

    int size() { return size_; }
    bool empty() { return size_ == 0; }

    void add(T x);
    T pop();

private:
    T *data_;
    int size_;
    int idx_;

    void siftUp(int i);
    void siftDown(int i);
};

template <typename T> void MaxHeap<T>::add(T x) {
    data_[idx_++] = x;
    size_++;
    siftUp(size_);
}

template <typename T> T MaxHeap<T>::pop() {
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
#endif // _HEAP_H