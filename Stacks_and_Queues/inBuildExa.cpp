#include <iostream>
#include <stack>

int main() {
    std::stack<std::string> cars;
    cars.push("Volvo");
    cars.push("BMW");
    cars.push("Ford");

    // Access top element
    // std::cout << "Top: " << cars.top() << std::endl;

    // Remove top element
    cars.pop();
    cars.pop();
    cars.pop();
    cars.pop();

    // Check if empty
    // if (!cars.empty()) {
    //     std::cout << "Size: " << cars.size() << std::endl;
    // }
    return 0;
}   