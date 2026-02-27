#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>


static void testConstructors() {
    std::cout << "\n-- Constructor tests --\n";
    try {
        Bureaucrat a("Alice", 1);
        std::cout << a << std::endl;
    } catch (std::exception &e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 150);
        std::cout << b << std::endl;
    } catch (std::exception &e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    try {
        Bureaucrat badHigh("badHigh", 0);
        std::cout << badHigh << std::endl;
    } catch (std::exception &e) {
        std::cout << "Expected (151): " << e.what() << std::endl;
    }
}

static void testMutators() {
    std::cout << "\n-- Increment/Decrement tests --\n";
    try {
        Bureaucrat c("Carl", 2);
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
    } catch (std::exception &e) {
        std::cout << "Expected (incement past 1): " << e.what() << std::endl;
    }

    try {
        Bureaucrat d("Dana", 149);
        std::cout << d << std::endl;
        d.decrementGrade();
        std::cout << d << std::endl;
        d.decrementGrade();
        std::cout << d << std::endl;
    } catch (std::exception &e) {
        std::cout << "Expected (decrement past 150): " << e.what() << std::endl;
    }
}

int main() {
    testConstructors();
    testMutators();
}
