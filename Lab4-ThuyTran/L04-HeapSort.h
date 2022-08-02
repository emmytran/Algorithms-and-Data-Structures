//Thuy Uyen My Tran
//Lab 4 - Header file

#include <iostream>

//Create Heap class
class Heap {
private:
    int *heap;
    int capacity;
    int size;
    
    //Left node
    int leftNode(int i) {
        return 2 * i + 1;
    }
    
    //Right node
    int rightNode(int i) {
        return 2 * i + 2;
    };
    
    //Parent node
    int parent(int i) {
        return (i - 1) / 2;
    };
    
    //Swap function
    void swapNodes(int *first, int *second) {
        int temp = *first;
        *first = *second;
        *second = temp;
    }
    
public:
    Heap() {
        this->capacity = 0;
        this->size = 0;
        this->heap = new int[0];
    }
    
    Heap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->heap = new int[capacity];
    }
    
    void printArray() {
        for (int i = 0; i < this->size; i++)
        {
            std::cout << this->heap[i] << " ";
        }
        std::cout << std::endl;
    };
    
    //Modify value
    void modifyValMax(int index, int val) {
        this->heap[index] = val;
        max_heapify(index);
    }
    
    //Function to insert value
    void insert_val_maxHeap(int val) {
        
        this->heap[this->size] = val;
        this->size++;
        
        for (int i = this->size - 1; i >= 0; i--) {
            if (this->heap[i] > this->heap[this->parent(i)])
            {
                std::swap(this->heap[i], this->heap[this->parent(i)]);
                i = this->parent(i);
            }
        }
    }
    
    void max_heapify(int i) {
        //Assign left and right child of the heap
        int l = this->leftNode(i);
        int r = this->rightNode(i);
        int largest = i;
        
        //If left node is larger
        if (l < size && heap[l] > heap[largest]) {
            largest = l;
        }
        
        //If right node is larger
        if (r < size && heap[r] > heap[largest]) {
            largest = r;
        }
        
        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            max_heapify(largest);
        }
    }
    
    //Function to extract the maximum value of heap
    int extract_maximum() {
        int root = heap[0];
        heap[0] = heap[size - 1];
        this->size--;
        max_heapify(0);
        return root;
    }
    
    //Function to print the array in descending order
    void descendingHeapSort(int arr[], int n) {
        this->buildMaxHeap(arr, n);
        
        for (int i = n - 1; i >= 0; i--) {
            this->max_heapify(n - 1);
        }
    }
    
    //Function to print the array in ascending order
    void ascendingHeapSort(int arr[], int n) {
        this->buildMinHeap(arr, n);
        for (int i = n - 1; i >= 0; i--) {
            this->min_heapify(n - 1);
        }
    }
    
    //buildMaxHeap fuction
    void buildMaxHeap(int arr[], int n) {
        this->size = n;
        for (int i = 0; i < n; i++) {
            this->heap[i] = arr[i];
        }
        
        int idx = n / 2 - 1;
        for (int i = idx; i >= 0; i--) {
            max_heapify(i);
        }
    }
    
    //Modify min value
    void modifyValMin(int index, int val) {
        this->heap[index] = val;
        min_heapify(index);
        
    };
    
    //Adds value at the end of the array
    void insert_val_minHeap(int val) {
        this->heap[this->size] = val;
        this->size++;
        for (int i = this->size - 1; i >= 0; i--) {
            if (this->heap[i] < this->heap[this->parent(i)]) {
                std::swap(this->heap[i], this->heap[this->parent(i)]);
                i = this->parent(i);
            }
        }
    }
    
    //Function to maintain heap
    void min_heapify(int i) {
        int lcIndex = this->leftNode(i);
        int rcIndex = this->rightNode(i);
        int smallest = i;
        
        if (lcIndex < size && this->heap[lcIndex] < this->heap[smallest])
        {
            smallest = lcIndex;
        }
        
        if (rcIndex < size && this->heap[rcIndex] < this->heap[smallest])
        {
            smallest = rcIndex;
        }
        if (smallest != i) {
            std::swap(this->heap[i], this->heap[smallest]);
            min_heapify(smallest);
        }
        
    }
    
    //Function to return the smallest value
    int extract_minimum() {
        
        int root = heap[0];
        heap[0] = heap[size - 1];
        this->size--;
        min_heapify(0);
        return root;
        
    }
    
    //Heap the list
    void buildMinHeap(int arr[], int n) {
        
        this->size = n;
        for (int i = 0; i < n; i++) {
            this->heap[i] = arr[i];
        }
        
        int idx = n / 2 - 1;
        for (int i = idx; i >= 0; i--) {
            this->min_heapify(i);
        }
    }
};
