#include "identify.hpp"
#include "Base.hpp"
#include <iostream>

int main() {
    std::cout << "=== Random generation tests ===\n";
    for (int i = 0; i < 10; i++) {
        Base* p = generate();
        std::cout << "[" << i << "] identify(ptr): ";
        identify(p);
        std::cout << "    identify(ref): ";
        identify(*p);
        delete p;
    }
    std::cout << "\n=== Null pointer edge case ===\n";
    Base* nullp = 0;
    std::cout << "identify(ptr): ";
    identify(nullp);
    class D : public Base {};
    D d;
    std::cout << "\n=== Unknown type edge case ===\n";
    std::cout << "identify(ptr): ";
    identify(&d);
    std::cout << "identify(ref): ";
    identify(d);
    return 0;
}
