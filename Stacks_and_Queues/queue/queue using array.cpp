#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void push(int data) {
        if (rear == 4) {
            cout << "Queue is Full\n";
            return;
        }

        rear++;
        arr[rear] = data;
    }

    void pop() {
        if (empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        front++;
    }

    int Front() {
        if (empty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return arr[front];
    }

    bool empty() {
        return front > rear;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    while (!q.empty()) {
        cout << q.Front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}


