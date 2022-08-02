//Thuy Uyen My Tran
//Lab 3 - Part 1 (Selection Sort)
#include <iostream>
#include <chrono>

//Swap function
void swap(int *x, int *y) {
    //create a temporary value and assign it to x's value
    int temp = *x;
    //swap
    *x = *y;
    *y = temp;
}

//selection sort function and time function
void selectionSort(int arr[], int n) {
    clock_t timeReq;
    timeReq = clock();
    int i, j;
    int min_idx = 0;
  
    //Loop through the array
    for (i = 0; i < n-1; i++) {
        //Find the minimum element
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
  
        //Function to swap the minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    timeReq = clock() - timeReq;
    std::cout << "Time taken: " << ((float)timeReq / CLOCKS_PER_SEC) * 10e9 << " nanoseconds" << std::endl;
}
  
// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
  
int main() {
    int sortedArray[10] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int reversedArray[10] = {30, 29, 28, 27, 26, 25, 24, 23, 22, 21};
    int halfSortedArray[10] = {21, 22, 23, 24, 25, 27, 28, 26, 30, 29};
    int arrayLength = 10;
    
    selectionSort(sortedArray, arrayLength);
    std::cout << "Sorted array: ";
    printArray(sortedArray, arrayLength);
    std::cout << std::endl;
    
    selectionSort(reversedArray, arrayLength);
    std::cout << "Sorted array (reversed): ";
    printArray(reversedArray, arrayLength);
    std::cout << std::endl;
    
    selectionSort(halfSortedArray, arrayLength);
    std::cout << "Sorted array (half sorted): ";
    printArray(halfSortedArray, arrayLength);
    std::cout << std::endl;
    
    return 0;
}



