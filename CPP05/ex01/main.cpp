#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Basic objects ===" << std::endl;
    Bureaucrat bob("Bob", 50);
    Bureaucrat jim("Jim", 150);
    std::cout << bob << std::endl;
    std::cout << jim << std::endl;

    std::cout << "\n=== Form construction ===" << std::endl;
    try {
        Form ok("TopSecret", 100, 42);
        std::cout << ok << std::endl;
    } catch (std::exception &e) {
        std::cout << "Unexpected " << e.what() << std::endl;
    }

    try {
        Form bad("BadForm", 0, 42);
        std::cout << bad << std::endl;
    } catch (std::exception &e) {
        std::cout << "Expected (grade 0): " << e.what() << std::endl;
    }

    std::cout << "\n== Signing ===" << std::endl;
    Form formA("FormA", 100, 50);
    std::cout << formA << std::endl;

    bob.signForm(formA);
    std::cout << formA << std::endl;

    Form formB("FormB", 1, 1);
    std::cout << formB << std::endl;
    jim.signForm(formB);
    std::cout << formB << std::endl;
}
