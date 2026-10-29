#include <iostream>
using namespace std;

int main() {
    // Static initialization
    int arr1[5] = {1, 2, 3, 4, 5};
    
    // Dynamic initialization using loop
    int arr2[5];
    for(int i = 0; i < 5; i++) {
        arr2[i] = i * 10;
    }
    return 0;
}   



void insertElement(int arr[], int &size, int pos, int value) {
    // Shift elements from pos to end one position to the right
    for (int i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = value;
    size++; // Update logical size
}   
