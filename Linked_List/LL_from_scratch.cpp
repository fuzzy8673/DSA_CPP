#include <iostream>
using namespace std;

class LL {

private:
    // Node represents one element of the linked list
    struct Node {
        int value;
        Node* next;

        // Constructor for creating a node with a value
        Node(int value) {
            this->value = value;
            this->next = nullptr;
        }

        // Constructor for creating a node with a value and next pointer
        Node(int value, Node* next) {
            this->value = value;
            this->next = next;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    LL() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Insert a new node at the beginning
    void insertAtFirst(int value) {

        Node* node = new Node(value);

        node->next = head;
        head = node;

        // If this is the first node, tail also points to it
        if (tail == nullptr) {
            tail = head;
        }

        size++;
    }

    // Display the linked list
    void display() {

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }

        cout << "END" << endl;
    }

    // Insert a node at the end of the linked list
void insertAtLast(int value) {

    // If the list is empty
    if (tail == nullptr) {
        insertAtFirst(value);
        return;
    }

    // Create a new node
    Node* node = new Node(value);

    // Connect the current tail to the new node
    tail->next = node;

    // Update tail to the new node
    tail = node;

    size++;
}


// Insert a node at a specific index
void insert(int val, int index) {

    // Insert at the beginning
    if (index == 0) {
        insertAtFirst(val);
        return;
    }

    // Insert at the end
    if (index == size) {
        insertAtLast(val);
        return;
    }

    // Start from the head
    Node* temp = head;

    // Move temp to the node just before the required index
    for (int i = 1; i < index; i++) {
        temp = temp->next;
    }

    // Create a new node
    // Its next points to the node currently at index
    Node* node = new Node(val, temp->next);

    // Connect the previous node to the new node
    temp->next = node;

    size++;
}
};