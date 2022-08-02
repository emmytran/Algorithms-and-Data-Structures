//Thuy Uyen My Tran
//Lab 5 - Counting Sort

#include <iostream>

void countingSort(int array[], int size) {
    int output[size];
    int max = array[0];
    
    //Get maximum value in the array
    for(int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    
    //Step to declare counts array with max+1 value, then initialize each value by 0
    int counts[max+1];
    for (int i = 0; i < max + 1; i++) {
        counts [i] = 0;
    }
    
    //Step to find count of each element in input array and save it to counts array
    for (int i = 0; i < size; i++) {
        counts[array[i]]++;
    }
    
    //Function that finds cummlative sum in counts array
    for (int i = 1; i <= max; i++) {
        counts[i] += counts[i - 1];
    }
    
    //Function that places each element in the output array using the counts array.
    for (int i = size - 1; i >= 0; i--) {
        output[counts[array[i]] - 1] = array[i];
        counts[array[i]]--;
    }
    
    //Function that places each value from output array to the input array.
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

//Print array
void printArray(int array[], int size) {
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }
}

int main(){
    
    //Record the time from start to end
    clock_t startTime, endTime;
    
    //Take an array
    int array[] = {3, 5, 2, 3, 5, 31, 7, 8, 1, 10, 1, 20, 12, 24, 4};
    //Function to calculate the size of the array
    int size = sizeof(array) / sizeof(array[0]);
    
    std::cout << "Inserted array: ";
    printArray(array, size);
    
    startTime = clock();
    countingSort(array, size);
    endTime = clock();
    
    std::cout << std::endl << "Sorted array: ";
    printArray(array, size);
    std::cout << std::endl << "Time taken: " << (float)(endTime-startTime) << " milliseconds" << std::endl;
}

