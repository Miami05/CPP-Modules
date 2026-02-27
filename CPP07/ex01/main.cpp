#include "iter.hpp"
#include <iostream>
#include <string>

void addOne(int &x) { x += 1; }

void printInt(const int &x) { std::cout << x << " "; }

void printStr(const std::string &s) { std::cout << s << " "; }

int main() {
    int a[] = {1, 2, 3, 4};
    std::size_t nA = sizeof(a) / sizeof(a[0]);
    std::cout << "Before";
    iter(a, nA, printInt);
    std::cout << "\n";
    iter(a, nA, addOne);
    std::cout << "After : ";
    iter(a, nA, printInt);
    std::cout << "\n\n";
    const std::string s[] = {"hello", "iter", "world"};
    std::size_t nS = sizeof(s) / sizeof(s[0]);
    std::cout << "Strings: ";
    iter(s, nS, printStr);
    std::cout << "\n";
    iter((int *)0, 10, addOne);
    iter(a, 0, addOne);
    return 0;
}
