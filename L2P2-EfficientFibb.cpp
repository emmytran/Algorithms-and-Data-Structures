//Thuy Uyen My Tran
//Lab 2 - Part 2

#include <iostream>
#include <sys/time.h>
#include <iomanip>

int fib(int n) {
    int a = 0, b = 1, c, i;
    if (n == 0) {
        return a;
    }
    for(i = 2; i <= n; i++) {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}


int main() {
    int n;
    unsigned long int result;

    clock_t start, end;

    std::cout << "Input: ";
    std::cin >> n;

    //Time at start
    start = clock();

    result = fib(n);
    //Record time at the end
    end = clock();
    std::cout << "Output: " << result << std::endl;

    int timeTaken = int(end - start); //Calculate the time taken
    
    std::cout << "Time: " << std::fixed << timeTaken << std::setprecision(5);
    std::cout << " seconds" << std::endl;
    return 0;
}

