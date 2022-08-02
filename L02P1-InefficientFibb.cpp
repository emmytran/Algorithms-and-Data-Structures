//Thuy Uyen My Tran
//Lab 2 - Part 1

#include <iostream>
#include <sys/time.h>
#include <iomanip>

unsigned long int fib(int n) {
    if (n <= 1) {    //stop if the input is less than 0
        return n;
    }

    else {   //recursive function
        return (fib(n - 1) + fib(n - 2));
    }
}

int main() {

    int n;
    unsigned long int ans;

    clock_t start, end;

    std::cout << "Input: ";
    std::cin >> n; //Take input

    //Time(&start);
    start = clock();
    ans = fib(n);
    
    //Record the time at the end
    end = clock();
    std::cout << "Output: " << ans << "\n";

  //Calculate total time taken by the program
    unsigned long int timeTaken = (end - start);
    std::cout << "Time: " << std::fixed << timeTaken << std::setprecision(5);
    std::cout << " seconds" << std::endl;
    return 0;

}
