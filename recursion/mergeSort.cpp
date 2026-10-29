// #include <iostream>
// #include <vector>
// using namespace std;

// class MergeSort {

// public:

//     int main() {

//         vector<int> arr = {8, 3, 4, 12, 5, 6};

//         arr = mergeSort(arr);

//         for (int x : arr) {
//             cout << x << " ";
//         }

//         return 0;
//     }

//     vector<int> mergeSort(vector<int> arr) {

//         // Base condition
//         if (arr.size() == 1) {
//             return arr;
//         }

//         int mid = arr.size() / 2;

//         // Create left and right arrays
//         vector<int> left(arr.begin(), arr.begin() + mid);
//         vector<int> right(arr.begin() + mid, arr.end());

//         // Recursively sort both halves
//         left = mergeSort(left);
//         right = mergeSort(right);

//         // Merge sorted halves
//         return merged(left, right);
//     }

// private:

//     vector<int> merged(vector<int> left, vector<int> right) {

//         vector<int> mix(left.size() + right.size());

//         int i = 0;
//         int j = 0;
//         int k = 0;

//         // Compare elements from left and right
//         while (i < left.size() && j < right.size()) {

//             if (left[i] < right[j]) {
//                 mix[k] = left[i];
//                 i++;
//             }
//             else {
//                 mix[k] = right[j];
//                 j++;
//             }

//             k++;
//         }

//         // Copy remaining elements from left
//         while (i < left.size()) {
//             mix[k] = left[i];
//             i++;
//             k++;
//         }

//         // Copy remaining elements from right
//         while (j < right.size()) {
//             mix[k] = right[j];
//             j++;
//             k++;
//         }

//         return mix;
//     }
// };


// int main() {

//     MergeSort obj;

//     obj.main();

//     return 0;
// }



// easy version



#include <iostream>
#include <vector>
using namespace std;

vector<int> merged(vector<int> left, vector<int> right) {

    vector<int> mix(left.size() + right.size());

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < left.size() && j < right.size()) {

        if (left[i] < right[j]) {
            mix[k] = left[i];
            i++;
        }
        else {
            mix[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < left.size()) {
        mix[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size()) {
        mix[k] = right[j];
        j++;
        k++;
    }

    return mix;
}


vector<int> mergeSort(vector<int> arr) {

    // Base condition
    if (arr.size() == 1) {
        return arr;
    }

    int mid = arr.size() / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    // Recursively sort left and right
    left = mergeSort(left);
    right = mergeSort(right);

    return merged(left, right);
}


int main() {

    vector<int> arr = {8, 3, 4, 12, 5, 6};

    arr = mergeSort(arr);

    cout << "Sorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}