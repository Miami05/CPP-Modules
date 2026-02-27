#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	Bureaucrat low("Low", 150);
	Bureaucrat mid("Mid", 70);
	Bureaucrat boss("Boss", 1);

	ShrubberyCreationForm sh("home");
	RobotomyRequestForm ro("Bender");
	PresidentialPardonForm pr("Arthur Dent");

	std::cout << boss << std::endl;
	std::cout << sh << std::endl;
	std::cout << ro << std::endl;
	std::cout << pr << std::endl;

	std::cout << "\n--- Execute unsigned (should fail) ---\n";
	boss.executeForm(sh);

	std::cout << "\n--- Low tries sign (should fail) ---\n";
	low.signForm(pr);

	std::cout << "\n--- Boss signs and executes all (should work) ---\n";
	boss.signForm(sh);
	boss.executeForm(sh);

	boss.signForm(ro);
	boss.executeForm(ro);

	boss.signForm(pr);
	boss.executeForm(pr);

	std::cout << "\n--- Mid tries execute presidential (should fail exec grade) ---\n";
	mid.executeForm(pr);

	return 0;
}

