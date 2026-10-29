#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* head;
    Node* tail;

public:
    Queue() {
        head = tail = NULL;
    }

    void push(int data) {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = NULL;

        if (empty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
    }

    int front() {
        if (empty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return head->data;
    }

    bool empty() {
        return head == NULL;
    }
};

int main() {

    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}
