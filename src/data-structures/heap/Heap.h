#ifndef _HEAP_H
#define _HEAP_H

template<typename T>
class MaxHeap {
public:
    MaxHeap(int capacity): data_(new T[capacity+1]), size_(0) {}
    
    ~MaxHeap() {
        delete [] data_;
    }

    int size() {
        return size_;
    }

    bool empty() {
        return size_ == 0;
    }

private:
    T *data_;
    int size_;
};


#endif // _HEAP_H