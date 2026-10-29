#include <iostream>
using namespace std;


void countdown(int n)
{
    // Base case
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    // Recursive call
    countdown(n - 1);
}
int main()
{
    countdown(5);
return 0;
}
