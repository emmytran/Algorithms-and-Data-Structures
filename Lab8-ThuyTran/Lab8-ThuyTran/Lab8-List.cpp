#include "BinarySearchTree.h"
#include <iostream>

BST::BST() {
    this->root = nullptr;
}

Node* BST::InsertNode(Node* root, int data) {
    if (root == nullptr) {
        this->root = new Node(data);
        return this->root;
    }
    Node* ptr = root;
    Node* bptr = ptr;
    while (ptr) {
        if (ptr->data == data) return this->root;
        bptr = ptr;
        if (data < ptr->data) ptr = ptr->LeftChild;
        else ptr = ptr->RightChild;
    }

    if (data < bptr->data) bptr->LeftChild = new Node(data);
    else bptr->RightChild = new Node(data);
    return this->root;
}

void BST::printTree(Node* root) {
    if (root) {
        printTree(root->LeftChild);
        printTree(root->RightChild);
        std::cout << root->data << " ";
    }
}

int BST::Largest(Node* root) {
    Node* ptr = root;
    while (ptr->RightChild) ptr = ptr->RightChild;
    return ptr->data;
}

bool BST::FindNode(Node* root, int data) {
    Node* ptr = root;
    while (ptr) {
        if (ptr->data == data) return true;
        if (data < ptr->data) ptr = ptr->LeftChild;
        else ptr=ptr->RightChild;
    }
    return false;
}
