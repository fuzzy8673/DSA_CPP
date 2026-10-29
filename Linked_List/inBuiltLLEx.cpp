#include <iostream>  // For input/output operations
#include <list>      // For the std::list (doubly linked list) container

int main() {
    // Create a doubly linked list of integers
    std::list<int> myList;

    // --- Insertion Operations ---

    // Add 10 to the end of the list
    // List: 10
    myList.push_back(10);

    // Add 20 to the end of the list
    // List: 10, 20
    myList.push_back(20);

    // Add 5 to the front of the list
    // List: 5, 10, 20
    myList.push_front(5);

    // Insert 15 at a specific position (after the first element)
    // myList.insert(myList.begin() + 1, 15);
    // List: 5, 15, 10, 20

    // --- Traversal (print all elements) ---
    std::cout << "List: ";
    // Range-based for loop iterates through each element
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // Output: 5 10 20

    // --- Deletion Operations ---

    // Remove ALL occurrences of value 10 from the list
    // List: 5, 20
    myList.remove(10);

    // Remove the first element (5)
    // List: 20
    myList.pop_front();

    // Alternative: remove the last element
    // myList.pop_back();

    // Alternative: erase by iterator
    // auto it = myList.begin();
    // myList.erase(it);  // removes element at iterator position

    // --- Accessing Elements ---
    // int first = myList.front();  // get first element
    // int last  = myList.back();   // get last element

    // --- Output after deletions ---
    std::cout << "After ops: ";
    for (int val : myList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // Output: 20


    return 0;
}

     