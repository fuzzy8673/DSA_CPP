#include <iostream>
using namespace std;

// A Node represents one element of the linked list
struct Node {

    int data;       // Stores the actual value

    Node* next;     // Stores the address of the next Node
};


// Function to traverse (visit) and print all nodes
// head contains the address of the first node
void traverse(Node* head) {

    // Create a pointer named 'current'
    // Initially, current points to the first node
    Node* current = head;

    // Continue until current becomes NULL
    // NULL means there are no more nodes
    while (current != NULL) {

        // Access the data of the node pointed to by current
        // The -> operator is used to access members through a pointer
        cout << current->data << " ";

        // Move current to the next node
        // current->next contains the address of the next node
        current = current->next;
    }
}

void insertAtBeginning(Node*& head, int value) {
 
    Node* newNode = new Node;
 
    newNode->data = value;
    newNode->next = head;
 
    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
 
    if (head == NULL) {
        head = newNode;
        return;
    }
 
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}




int main() {

    // Dynamically create one Node in memory
    // 'new Node' allocates memory for a Node
    // head stores the address of that newly created Node
    Node* head = new Node;


    // Store 100 in the data part of the node
    head->data = 100;


    // This is the only node currently in the list
    // Therefore, it does not point to another node
    // NULL indicates the end of the linked list
    head->next = NULL;


    // This would directly print the data of the first node
//     cout << head->data << endl;

insertAtBeginning(head,99);
insertAtEnd(head,101);


    // Call the traverse function
    // Pass the address of the first node (head)
    traverse(head);


    return 0;
}
