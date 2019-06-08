#ifndef _HEAP_H
#define _HEAP_H

#include <algorithm>
#include <iostream>

template <typename T> class MyHeap {
public:
    MyHeap(int capacity)
        : data_(new T[capacity + 1]), size_(0), capacity_(capacity) {}
    MyHeap(T arr[], int capacity);
    ~MyHeap() { delete[] data_; }

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

template <typename T>
MyHeap<T>::MyHeap(T arr[], int capacity)
    : data_(new T[capacity + 1]), size_(capacity), capacity_(capacity) {
    for (int i = 1; i <= capacity; i++)
        data_[i] = arr[i - 1];

    for (int i = capacity / 2; i >= 1; i--)
        siftDown(i);
}

template <typename T> void MyHeap<T>::add(T x) {
    assert(size_ + 1 <= capacity_);
    data_[++size_] = x;
    siftUp(size_);
}

template <typename T> T MyHeap<T>::peek() {
    assert(size_ > 0);
    return data_[1];
}

template <typename T> T MyHeap<T>::pop() {
    assert(size_ > 0);
    T res = data_[1];
    std::swap(data_[1], data_[size_--]);
    siftDown(1);

    return res;
}

template <typename T> void MyHeap<T>::siftUp(int i) {
    while (i / 2 && data_[i] < data_[i / 2]) {
        std::swap(data_[i / 2], data_[i]);
        i /= 2;
    }
}

template <typename T> void MyHeap<T>::siftDown(int i) {
    int min = i;
    if (2 * i <= size_ && data_[2 * i] < data_[min])
        min = 2 * i;
    if (2 * i + 1 <= size_ && data_[2 * i + 1] < data_[min])
        min = 2 * i + 1;
    if (min != i) {
        std::swap(data_[i], data_[min]);
        siftDown(min);
    }
}

template <typename T> void MyHeap<T>::printHeap() { printNode(1, ""); }

template <typename T>
void MyHeap<T>::printNode(int i, const std::string &prefix) {
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