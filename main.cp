
#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits>
#include "MaxHeap.h"

void PrintTree(std::vector<int> A) {
    for (const auto& x : A) {
        std::cout << x << " ";
    }    
    std::cout << "\n";
}

int main()
{
    MaxHeap heap;
    std::vector<int> A {0, 1, 2 ,3 ,4, 5, 6, 7 ,8 ,9 ,10};
    std::cout << "Building heap..." << std::endl;
    heap.BuildMaxHeap(A);
    PrintTree(A);
    std::cout << "Inserting 11 into the tree..." << std::endl;
    heap.MaxHeapInsert(A, 11);
    PrintTree(A);
    std::cout << "Extracting max..." << std::endl;
    heap.HeapExtractMax(A);
    PrintTree(A);
    std::cout << "Increase 4th node to 20..." << std::endl;
    heap.HeapIncreaseValue(A, 4, 20);
    PrintTree(A);
    std::cout << "Sorting..." << std::endl;
    heap.HeapSort(A);
    PrintTree(A);

    return 0;
}
