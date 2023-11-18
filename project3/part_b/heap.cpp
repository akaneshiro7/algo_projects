
#include "Heap.h"
using namespace std;

template <class T>
Heap<T>::Heap() {}

template <class T>
void Heap<T>::initializeMaxHeap(const std::vector<T>& input) {
    data = input;
}

template <class T>
void Heap<T>::buildMaxHeap() {
    int n = data.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(i, n);
}

template <class T>
void Heap<T>::maxHeapify(int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && data[l] > data[i])
        largest = l;
    if (r < n && data[r] > data[largest])
        largest = r;
    if (largest != i) {
        swap(data[i], data[largest]);
        maxHeapify(largest, n);
    }
}

template <class T>
void Heap<T>::heapsort() {
    buildMaxHeap();
    for (int i = data.size() - 1; i >= 0; i--) {
        swap(data[0], data[i]);
        maxHeapify(0, i);
    }
}

template <class T>
T Heap<T>::getItem(int n) const {
    if (n < data.size())
        return data[n];
    throw out_of_range("Index out of range");
}

