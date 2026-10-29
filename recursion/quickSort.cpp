#include <iostream>
using namespace std;

void sort(int arr[], int low, int hi) {
    if (low >= hi) {
        return;
    }
    int s = low;
    int e = hi;
    // Find middle element and choose it as pivot
    int m = s + (e - s) / 2;
    int pivot = arr[m];
    while (s <= e) {

        // Move s until an element >= pivot is found
        while (arr[s] < pivot) {    // 1  4  3  2  5   // p= 3
            s++;
        }

        // Move e until an element <= pivot is found
        while (arr[e] > pivot) {
            e--;
        }

        // Swap elements
        if (s <= e) {
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;

            s++;
            e--;
        }
    }

    // Sort left part
    sort(arr, low, e);

    // Sort right part
    sort(arr, s, hi);
}

int main() {
    int arr[] = {5, 2, 7, 9, 4, 8};   
    int n = 1;
    sort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}