#include "heap.h"
#include <iostream>

// Constructor
template <typename T>
heap<T>::heap() {}

// Get Elements Parent
template <typename T>
int heap<T>::parent(int i) const {
    return (i - 1) / 2;
}

// Get Left Child
template <typename T>
int heap<T>::left(int i) const {
    return 2 * i + 1;
}

// Get Right Child
template <typename T>
int heap<T>::right(int i) const {
    return 2 * i + 2;
}

// Get nth item
template <typename T>
T heap<T>::getItem(int n) const {
    int size = heapArray.size();
    if (n >= 0 && n < size) {
        return heapArray[n];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

// Create Max Heap
template <typename T>
void heap<T>::initializeMaxHeap() {
    int size = heapArray.size();
    for (int i = (size / 2) - 1; i >= 0; --i) {
        maxHeapify(i);
    }
}

// Max Heapify heap recursively
template <typename T>
void heap<T>::maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int size = heapArray.size();
    int max = i;

    if (l < size && heapArray[l] > heapArray[i]) {
        max = l;
    }

    if (r < size && heapArray[r] > heapArray[max]) {
        max = r;
    }

    if (max != i) {
        std::swap(heapArray[i], heapArray[max]);
        maxHeapify(max);
    }
}

// Call initialize Max Heap to build max heap
template <typename T>
void heap<T>::buildMaxHeap() {
    initializeMaxHeap();
}

// Sort array by using max heap from bottom up
template <typename T>
void heap<T>::heapsort() {
    buildMaxHeap();

    for (int i = heapArray.size() - 1; i > 0; --i) {
        std::swap(heapArray[0], heapArray[i]);
        maxHeapify(0);
    }
}

// Insert an item into the heap
template <typename T>
void heap<T>::insert(T item) {
    heapArray.push_back(item);
    int currentIndex = heapArray.size() - 1;

    while (currentIndex > 0 && heapArray[currentIndex] > heapArray[parent(currentIndex)]) {
        std::swap(heapArray[currentIndex], heapArray[parent(currentIndex)]);
        currentIndex = parent(currentIndex);
    }
}

// Print heap content
template <typename T>
void heap<T>::printHeap() const {
    for (const T& item : heapArray) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

// Return number of items in the heap
template <typename T>
int heap<T>::getSize(){
    return heapArray.size();
}
