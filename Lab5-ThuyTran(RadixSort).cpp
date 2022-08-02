//Thuy Uyen My Tran
//Lab 5 - Radix Sort

#include <iostream>

//Function to find maximum value of the array
int getMax(int array[], int n) {
    int maxVal = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}

//Function to do counting sort
void countSort(int array[], int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };
    
    //Find the count of each element in the input array then save it to count array
    for (i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }
    
    //Function to find the cumulative sum in count array
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    //Function that places each element in the output array using the count array
    for (i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    
    //Loop to place each value from the output array to the input array
    for (i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

//Radix Sort
void radixSort(int array[], int n) {
    
    //Find the maximum number to know number of digits
    int m = getMax(array, n);
    
    //Counting sort
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(array, n, exp);
    }
}

//Function to print the array
void print(int array[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
}

int main() {
    //Calculate the start time and end time
    clock_t startTime, endTime;
    
    //Array inserted
    int array[] = {3, 5, 2, 3, 5, 31, 7, 8, 1, 10, 1, 20, 12, 24, 4};
    //Function to calculatte the size of the array
    int n = sizeof(array) / sizeof(array[0]);
    
    std::cout << "Provided array: ";
    print(array, n);
    std::cout << std::endl;
    
    startTime = clock();
    radixSort(array, n);
    endTime = clock();
    
    //Print out sorted array
    std::cout << "Sorted array: ";
    radixSort(array, n);
    print(array, n);
    
    //Print out time taken for the program
    std::cout << std::endl << "Time taken: "<< (float)(endTime-startTime) << " milliseconds" << std::endl;
    return 0;
}
