//Thuy Uyen My Tran
//Lab 1 - Part 2: Linked List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void insert(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

Node* removeLast(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    
    Node* second_last = head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    delete (second_last->next);
    second_last->next = NULL;
    
    return head;
}

Node* removeFirst(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void printList(Node *head) {
    if (head == NULL) {
        return;
    }
    Node *node = head;
    while (node != NULL) {
        cout << node->data;
        if (node->next != NULL) {
            cout << ", ";
        }
        node = node->next;
    }
    cout << endl;
}

int main(){
    Node *head = NULL;
    cout << "Items in the linked list: ";
    insert(&head, 60);
    insert(&head, 40);
    insert(&head, 20);
    
    printList(head);
    
    head = removeFirst(head);
    cout << "Items in the linked list after deleting the first element: ";
    printList(head);
    
    head = removeLast(head);
    cout << "Items in the linked list after deleting the last element: ";
    printList(head);
}
