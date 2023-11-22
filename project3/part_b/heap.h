#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "heap.h"
template <typename T>
class heap {
private:
    std::vector<T> heapArray;

    int parent(int i) const;
    int left(int i) const;
    int right(int i) const;

public:
    heap();

    T getItem(int n) const;

    void initializeMaxHeap();
    void maxHeapify(int i);
    void buildMaxHeap();
    void heapsort();

    void insert(T item);
    void printHeap() const;

    int getSize();
};

#include "heap.cpp" // Include the implementation file

#endif // HEAP_H
