//Thuy Uyen My Tran

#include <iostream>

using namespace std;

class Stack {
private:
    int top;
    int stk[10];
public:
    Stack() {
        top = -1;
        for (int i = 0; i < 10; i++) {
            stk[i] = 0;
        }
    }
    
    bool isFull() {
        if (top == 9) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void push(int val) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
        }
        else {
            top++;
            stk[top] = val;
        }
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
        }
        else {
            cout << "Popped item is: " << stk[top] << endl;
            top--;
        }
        return 0;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
        }
        else {
            cout << "Peeked item is " << stk[top] << endl;
         }
        return 0;
    }
    
    void printStack() {
        cout << "Items in the stack: ";
        for (int i = top; i >= 0; i--) {
            cout << stk[i];
            if (i != 0) {
                cout << ", ";
            }
        }
        cout << endl;
    }
};
int main() {
    Stack stk;
    stk.push(20);
    stk.push(40);
    stk.push(60);
    
    stk.printStack();
    
    stk.pop();
    stk.peek();
    
    stk.printStack();
    return 0;
}
