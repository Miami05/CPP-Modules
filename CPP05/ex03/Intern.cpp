#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string &target) { return new ShrubberyCreationForm(target); }
AForm *Intern::createRobotomy(const std::string &target) { return new RobotomyRequestForm(target); }
AForm *Intern::createPresidential(const std::string &target) { return new PresidentialPardonForm(target); }

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    CreateFn creators[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential,
    };
    for (int i = 0; i < 3; i++) {
        if (name == names[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target);
        }
    }
    std::cout << "Intern couldn't create form: " << name << std::endl;
    return 0;
}
