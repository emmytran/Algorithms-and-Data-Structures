//Thuy Uyen My Tran
//Lab 8

#include "BinarySearchTree.h"
#include <iostream>

int main() {
    BST* bst = new BST();
    
    //Array elements
    int arr[10] = {7, 20, 8, 9, 6, 1, 19, 15, 2, 10};
    std::cout << "Inserted elements: ";
    
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
        bst->InsertNode(bst->getRoot(), arr[i]);
    }
    
    //Print the array post order
    std::cout << "\nPost-order: ";
    bst->printTree(bst->getRoot());
    
    //Print the largest element in the list
    std::cout << "\nLargest element in the list is: ";
    std::cout << bst->Largest(bst->getRoot()) << std::endl;
    
    //Lookup a number that is not on the list
    std::cout << "Insert a number for look up >> ";
    int number;
    std::cin >> number;
    bool ptr = bst->FindNode(bst->getRoot(), number);
    
    if (ptr) {
        std::cout << number;
    }
    
    else {
        std::cout << number << " is not a member of List";
    }
    
    //Lookup a number that is on the list
    std::cout << "\nInsert a number for look up >> ";
    std::cin>>number;
    if (bst->FindNode(bst->getRoot(), number)) {
        std::cout << number;
    }
    else {
        std::cout << number << " is not a member of List";
    }
    
    std::cout << std::endl;
    
    return 0;
}
