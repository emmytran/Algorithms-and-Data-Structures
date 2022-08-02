//Thuy Uyen My Tran
//Lab 6 - Quicksort

#include <iostream>

//Function for partition
int partition(int arr[], int low, int high) {
    //Find pivot
    int pivot = arr[high];
    //Index of the smaller element
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//Function to get the Median
int getMedian(int arr[], int first, int last) {
    int mid = (last - first) / 2;
    //Check for midddle elememt
    if ((arr[first] < arr[mid] and arr[mid] < arr[last]) or (arr[last] < arr[mid] and arr[mid] < arr[first])) {
        return mid;
    }
    //Check for first element
    if ((arr[mid] < arr[first] and arr[first] < arr[last]) or (arr[last] < arr[first] and arr[first] < arr[mid])) {
        return first;}
    else {
        return last;
    }
}

//Function that generates random pivot, swaps the pivot with the first element and calls the partition function
int partition_random(int arr[], int low, int high) {
    //Function to generate a random number in between low and high
    srand(high);
    int random = low + rand() % (high - low);
    std::swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

//Function to get first, middle, and last elements; then swaps it with the first element and calls the partition function
int partition_median(int arr[], int low, int high) {
    int median = getMedian(arr, low, high);
    std::swap(arr[median], arr[high]);
    return partition(arr, low, high);
}

//Function that selects first element as pivot, then swaps pivot with last element and calls the partition function
int partition_first(int arr[], int low, int high) {
    std::swap(arr[low], arr[high]);
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high, int choice) {
    if (low < high) {
        int pi;        if (choice == 1) {
            pi = partition_first(arr, low, high);
        }
        else if (choice == 2) {
            pi = partition_random(arr, low, high);
        }
        else if (choice == 3) {
            pi = partition_median(arr, low, high);
        }
        quickSort(arr, low, pi - 1, choice);
        quickSort(arr, pi + 1, high, choice);
    }
}

int main() {
    clock_t startTime, endTime;
    int list[] = {1, 5, 8, 4, 2 , 1, 55, 51, 23, 20, 15, 12, 10, 22, 1, 5, 4, 18, 12, 46, 34, 29, 30, 20, 54, 3, 1, 22, 24, 12, 26, 37, 53, 43, 41};
    
    //Calculate the size of the array
    int size = sizeof(list) / sizeof(list[0]);
    int choice;

    std::cout << "Select type of pivot:\n  1 - The first element in the list element\n  ";
    std::cout << "2 - A random element in the array\n  3 - The median of the first, middle, and last elements in the array\n";
    std::cin >> choice;

    //User choices using Switch Case
    switch (choice) {
    case 1:
        startTime = clock();
        quickSort(list, 0, size - 1, choice);
        endTime = clock();
        std::cout << "Time to sort with first element as pivot " << (float)(endTime - startTime) << " miliseconds" << std::endl;
        break;

    case 2:
        startTime = clock();
        quickSort(list, 0, size - 1, choice);
        endTime = clock();
        std::cout << "Time to sort with random element as pivot " << (float)(endTime - startTime) << " miliseconds" << std::endl;
        break;
    
    case 3:
        startTime = clock();
        quickSort(list, 0, size - 1, choice);
        endTime = clock();
        std::cout << "Time to sort with medain of first, middle and last elements as pivot " << (float)(endTime - startTime) << " miliseconds" << std::endl;
        break;
    
    default:
        std::cout << "Invalid pivot type selected.";
    }
    
    std::cout << "List after sorting is: ";
    for (int i = 0; i < size; i++) {
        std::cout << list[i] << " ";
    }

    return 0;
}

