#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {10, 20, 30, 40, 50};

    int n = 5;
    int position = 2;

    // Shift elements to the left
    for(int i = position; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    // Display array
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
