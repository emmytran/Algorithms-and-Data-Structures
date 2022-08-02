
//Merge Sort
#include <iostream>

//function to print array
void printArr(int arr[], int lastIdx) {
    for (int i = 0; i <= lastIdx; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

//merge 2 subarrays left and right into array
void merge(int arr[], int left, int mid, int right) {
    
    int p1 = mid - left + 1;
    int p2 = right - mid;
    
    int leftArray[p1], rightArray[p2];
    
    for (int i = 0; i < p1; i++)
        leftArray[i] = arr[left + i];
    
    for (int j = 0; j < p2; j++)
        rightArray[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < p1 && j < p2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    
    while (i < p1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    
    while (j < p2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        //create middle point
        int middle = left + (right - left) / 2;
        
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        
        //merge subarrays that were sorted
        merge(arr, left, middle, right);
    }
}
        
void printMergeSort(int arr[], int a, int b) {
    //calculate time
    clock_t timeReq;
    timeReq = clock();
    
    mergeSort(arr, a, b);
    printArr(arr, b);

    
    timeReq = clock() - timeReq;
    std::cout << "Time taken: " << ((float)timeReq / CLOCKS_PER_SEC) * 10e9 << " nanoseconds" << std::endl;
}

int main() {
    
    int sortedArray[10] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int reversedArray[10] = {30, 29, 28, 27, 26, 25, 24, 23, 22, 21};
    int halfSortedArray[10] = {21, 22, 23, 24, 25, 27, 28, 26, 30, 29};
    
    std::cout << "Sorted array: ";
    printMergeSort(sortedArray, 0, 9);
    std::cout << std::endl;
    
    std::cout << "Sorted array (reversed array): ";
    printMergeSort(reversedArray, 0, 9);
    std::cout << std::endl;
    
    std::cout << "Sorted array (half sorted array): ";
    printMergeSort(halfSortedArray, 0, 9);
    std::cout << std::endl;
    return 0;
}

