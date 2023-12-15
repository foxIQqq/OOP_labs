#include "hex.h"

int main() {
    using Hex = form::Hex;
    Hex a, b, c;
    std::cout << "Enter your numbers:" << std::endl;
    std::cin >> a >> b;
    std::cout << "Sum: " << (a + b) << std::endl;
    
    std::cout << "Diff: " << (a - b) << std::endl;

    std::cout << "Copy (first number): " << (c = a) << std::endl;

    std::cout << "Equal: " << (a == b) << std::endl;

    std::cout << "Less: " << (a < b) << std::endl;

    std::cout << "More: " << (a > b) << std::endl;

}