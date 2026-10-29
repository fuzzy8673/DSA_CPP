#include <iostream>
using namespace std;

// Include the linked list class
#include "LL_from_scratch copy.cpp"


int main() {

    
    LL2 list2;
    list2.insertAtFirst(7);
    list2.insertAtFirst(6);
    list2.insertAtFirst(5);

    list2.insertAtLast(9);
    list2.insertAtLast(10);

    list2.insert(8,3);

    list2.display();

    // cout<<list2.deleteFirst()<<endl;
    // list2.display();

    // cout<<list2.deleteLast()<<endl;
    // list2.display();

    // cout<<list2.deleteItem(2)<<endl;
    // list2.display();

   



    return 0;
}