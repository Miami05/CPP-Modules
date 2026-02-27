#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include "Array.hpp"

int main() {
    try {
        Array<int> a(5);
        for (std::size_t i = 0; i < a.size(); ++i)
            a[i] = static_cast<int>(i) * 10;

        std::cout << "a: ";
        for (std::size_t i = 0; i < a.size(); ++i)
            std::cout << a[i] << " ";
        std::cout << "\n";

        // Deep copy check
        Array<int> b = a;
        b[0] = 999;
        std::cout << "After modifying b[0]=999:\n";
        std::cout << "a[0] = " << a[0] << " (should be 0)\n";
        std::cout << "b[0] = " << b[0] << " (should be 999)\n";

        // Const access check
        const Array<int> c = a;
        std::cout << "c[2] = " << c[2] << "\n";

        // Bounds check
        std::cout << "Trying a[10]...\n";
        std::cout << a[10] << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Caught exceptions: " << e.what() << "\n";
    }

    Array<std::string> empty;
    std::cout << "empty.size() = " << empty.size() << "\n";
    try {
        std::cout << empty[0] << "\n";
    } catch (const std::exception& e) {
        std::cout << "Caught exception (empty[0]): " << e.what() << "\n";
    }
    return 0;
}
