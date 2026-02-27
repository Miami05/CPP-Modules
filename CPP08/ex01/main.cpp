#include <cstddef>
#include <iostream>
#include "Span.hpp"
#include <nl_types.h>
#include <vector>
#include <cstdlib>
#include <ctime>

static void printLine(const char* title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    printLine("Basic Test");
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortestSpan = " << sp.shortestSpan() << "\n";
        std::cout << "longestSpan  = " << sp.longestSpan() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    printLine("Not enough numbers");
    try {
        Span sp2(3);
        sp2.addNumber(42);
        std::cout << sp2.shortestSpan() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    printLine("Full container");
    try {
        Span sp3(2);
        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    printLine("Range add test");
    try {
        Span sp4(10);
        std::vector<int> vals;
        vals.push_back(100);
        vals.push_back(50);
        vals.push_back(200);
        vals.push_back(150);
        sp4.addNumber(vals.begin(), vals.end());
        sp4.addNumber(75);
        sp4.addNumber(125);
        std::cout << "shortestSpan = " << sp4.shortestSpan() << "\n";
        std::cout << "longestSpan  = " << sp4.longestSpan() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
    printLine("Large random test (10,000 numbers)");
    try {
        Span big(10000);
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        for (int i = 0; i < 10000; ++i)
            big.addNumber(std::rand());
        std::cout << "shortestSpan = " << big.shortestSpan() << "\n";
        std::cout << "longestSpan  = " << big.longestSpan() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
}
