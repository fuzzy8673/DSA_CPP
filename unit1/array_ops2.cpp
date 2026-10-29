#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {10, 20, 30, 40, 50};

    int n = 5;
    int position = 2;
    int value = 25;

    // Shift elements to the right
    for(int i = n; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Insert new element
    arr[position] = value;

    n++;

    // Display array
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
