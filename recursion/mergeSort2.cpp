#include <iostream>
#include <vector>
using namespace std;


// ---------------------------------------------------------
// Function to merge two sorted arrays
// ---------------------------------------------------------
vector<int> merged(vector<int> left, vector<int> right) {

    // Create a new array to store the merged result
    // Size = size of left array + size of right array
    vector<int> mix(left.size() + right.size());

    // i -> points to the current element of left array
    // j -> points to the current element of right array
    // k -> points to the current position of merged array
    int i = 0;
    int j = 0;
    int k = 0;


    // -----------------------------------------------------
    // Compare elements of both arrays
    // and place the smaller element into mix[]
    // -----------------------------------------------------
    while (i < left.size() && j < right.size()) {

        if (left[i] < right[j]) {

            // Left element is smaller
            mix[k] = left[i];

            // Move to the next element of left array
            i++;
        }
        else {

            // Right element is smaller
            mix[k] = right[j];

            // Move to the next element of right array
            j++;
        }

        // Move to the next position of merged array
        k++;
    }


    // -----------------------------------------------------
    // If some elements are still remaining in left array,
    // copy them into mix[]
    // -----------------------------------------------------
    while (i < left.size()) {

        mix[k] = left[i];

        i++;
        k++;
    }


    // -----------------------------------------------------
    // If some elements are still remaining in right array,
    // copy them into mix[]
    // -----------------------------------------------------
    while (j < right.size()) {

        mix[k] = right[j];

        j++;
        k++;
    }


    // Return the completely merged sorted array
    return mix;
}


// ---------------------------------------------------------
// Merge Sort function
// ---------------------------------------------------------
vector<int> mergeSort(vector<int> arr) {

    // -----------------------------------------------------
    // BASE CASE
    //
    // If the array has 0 or 1 element,
    // it is already sorted.
    // -----------------------------------------------------
    if (arr.size() <= 1) {
        return arr;
    }


    // -----------------------------------------------------
    // Find the middle position of the array
    // -----------------------------------------------------
    int mid = arr.size() / 2;


    // -----------------------------------------------------
    // Divide the array into two halves
    //
    // Example:
    // arr = {8, 3, 4, 12, 5, 6}
    //
    // left  = {8, 3, 4}
    // right = {12, 5, 6}
    // -----------------------------------------------------

    vector<int> left(arr.begin(), arr.begin() + mid);

    vector<int> right(arr.begin() + mid, arr.end());


    // -----------------------------------------------------
    // Recursively sort the left half
    // -----------------------------------------------------
    left = mergeSort(left);


    // -----------------------------------------------------
    // Recursively sort the right half
    // -----------------------------------------------------
    right = mergeSort(right);


    // -----------------------------------------------------
    // Both left and right arrays are now sorted.
    //
    // Merge them together.
    // -----------------------------------------------------
    return merged(left, right);
}


// ---------------------------------------------------------
// Main Function
// ---------------------------------------------------------
int main() {

    // Original unsorted array
    vector<int> arr = {8, 3, 4, 12, 5, 6};


    // Display original array
    cout << "Original array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;


    // -----------------------------------------------------
    // Call Merge Sort
    // -----------------------------------------------------
    arr = mergeSort(arr);


    // -----------------------------------------------------
    // Display sorted array
    // -----------------------------------------------------
    cout << "Sorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    cout << endl;


    return 0;
}