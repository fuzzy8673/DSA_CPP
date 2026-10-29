#include <iostream>
using namespace std;

void insertElement(int arr[], int &n, int capacity, int pos, int value) {
    if (n >= capacity) {
        cout << "Array is full, cannot insert!" << endl;
        return;
    }
    if (pos < 0 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements to the right, starting from the last element
    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = value;
    n++;  // one more valid element now
}

int main() {
    int capacity = 10;
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;   // current number of elements

    cout << "Before insertion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    insertElement(arr, n, capacity, 2, 99);  // insert 99 at index 2

    cout << "After insertion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
