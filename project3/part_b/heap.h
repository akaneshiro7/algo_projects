#pragma  once

#include <vector>
#include <stdexcept>

using namespace std;

template <class T>
class Heap {
private:
    std::vector<T> data;

    void maxHeapify(int i, int n);
    void buildMaxHeap();

public:
    Heap();
    void initializeMaxHeap(const std::vector<T>& input);
    void heapsort();
    T getItem(int n) const;
};