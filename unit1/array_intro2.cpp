#include <iostream>
using namespace std;

int main() {
    // 1. Declaration only (garbage values inside)
    int arr1[5];

    // 2. Declaration + full initialization
    int arr2[5] = {10, 20, 30, 40, 50};

    // 3. Partial initialization (rest auto-filled with 0)
    int arr3[5] = {10, 20};   // becomes {10, 20, 0, 0, 0}

    // 4. Size inferred from initializer list
    int arr4[] = {1, 2, 3, 4};   // size = 4 automatically

    // 5. All zeros (common trick)
    int arr5[5] = {0};

    // Printing an array (no built-in print, must loop)
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}







//insert(arr, n, pos, value):
//    for i from n-1 down to pos:
//        arr[i+1] = arr[i]      // shift right
//    arr[pos] = value
//    n = n + 1
