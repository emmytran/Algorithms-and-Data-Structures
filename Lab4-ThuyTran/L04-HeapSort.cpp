//Thuy Uyen My Tran
//Lab 4 - Heap Sort

#include <iostream>
#include "Lab4-HeapSort-ThuyTran.h"

int main() {
    int choice;
    int arr[] = {4, 3, 2, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    Heap heap = Heap(10);
    
    std::cout << "Enter 0 for ascending order and 1 for descending order " << std::endl;
    std::cin >> choice;
    
    if (choice == 1) {
        heap.buildMaxHeap(arr, len);
        heap.printArray();
        heap.insert_val_maxHeap(9);
        
        
        std::cout << "After insertion: ";
        heap.printArray();
        
        std::cout << "After modifying first element: ";
        heap.modifyValMin(0, 6);
        heap.printArray();
        
        std::cout << "On calling extract_minimum: " << heap.extract_minimum() << std::endl;
        
        int Arr[] = {4, 3, 2, 6, 9};
        
        std::cout << "Array to Sort: 4, 3, 2, 6, 9" << std::endl;
        std::cout << "Sorted heap is: ";
        heap.descendingHeapSort(Arr, 5);
        
        heap.printArray();
    }
    
    else {
        heap.buildMinHeap(arr, len);
        heap.printArray();
        heap.insert_val_minHeap(9);
        
        std::cout << "After insertion: ";
        
        heap.printArray();
        
        std::cout << "After modifying the first element: ";
        heap.modifyValMax(0, 6);
        heap.printArray();
        
        std::cout << "On calling extract_maximum: " << heap.extract_maximum() << std::endl;
        
        int Arr[] = {4, 3, 9, 6, 2};
        
        std::cout << "Array to Sort: 4, 3, 2, 6, 9" << std::endl;
        std::cout << "Sorted heap is: ";
        heap.ascendingHeapSort(Arr, 5);
        heap.printArray();
    }
    
    return 0;
}


