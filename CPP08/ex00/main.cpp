// ex00/main.cpp  (tests)
#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

static void testVector() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);

    std::cout << "Vector test:\n";
    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found 20 at index: " << (it - v.begin()) << "\n"; // first occurrence
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    try {
        easyfind(v, 999);
        std::cout << "Should not print\n";
    } catch (const std::exception& e) {
        std::cout << "999 -> " << e.what() << "\n";
    }
}

static void testListConst() {
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    const std::list<int>& cl = l;

    std::cout << "\nList const test:\n";
    try {
        std::list<int>::const_iterator it = easyfind(cl, 3);
        std::cout << "Found: " << *it << "\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
}

static void testEmpty() {
    std::vector<int> empty;
    std::cout << "\nEmpty container test:\n";
    try {
        easyfind(empty, 1);
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
}

int main() {
    testVector();
    testListConst();
    testEmpty();
    return 0;
}
