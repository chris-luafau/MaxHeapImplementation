#include <vector>
#include <limits>
#include <stdexcept>
#include <cmath>
#include <algorithm>

class MaxHeap {
private:
    int heap_size;
public:
    MaxHeap() : heap_size(0) {};
    int Parent(int i) {
        if (i == 1) return NULL;
        return std::floor(i/2);
    }
    int Left(int i) {
        int L = 2 * i;
        if (L <= heap_size) return L;
        return NULL;
    }
    int Right(int i) {
        int R = 2 * i + 1;
        if (R <= heap_size) return R;
        return NULL;
    }
    void MaxHeapify(std::vector<int>& A, int i) {
        int L = Left(i);
        int R = Right(i);
        int largest = i;
        if (L <= heap_size && A[L] > A[i]) largest = L;
        if (R <= heap_size && A[R] > A[largest]) largest = R;
        if (largest != i) {
            std::swap(A[i], A[largest]);
            MaxHeapify(A, largest);
        }
    }
    void BuildMaxHeap(std::vector<int>& A) {
        heap_size = A.size()-1;
        for (int i = std::floor(A.size()-1/2); i >= 1; --i) {
            MaxHeapify(A, i);
        }
    }
    void HeapIncreaseValue(std::vector<int>& A, int i, int value) {
        if (value < A[i]) throw std::invalid_argument("Must insert a larger value");
        A[i] = value;
        while (i > 1 && A[i] > A[Parent(i)]) {
            std::swap(A[i], A[Parent(i)]);
            i = Parent(i);
        }
    }
    void HeapSort(std::vector<int>& A) {
        for (int i = A.size()-1; i >= 2; --i) {
            std::swap(A[1], A[i]);
            heap_size -= 1;
            MaxHeapify(A, 1);
        }
    }
    int HeapExtractMax(std::vector<int>& A) {
        int max = A[1];
        A[1] = A[heap_size];
        heap_size -= 1;
        MaxHeapify(A, 1);
        return max;
    }
    void MaxHeapInsert(std::vector<int>& A, int value) {
        heap_size += 1;
        A[heap_size] = std::numeric_limits<int>::min();
        HeapIncreaseValue(A, heap_size, value);
    }

};