#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    validateGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::validateGrade(int grade) const {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const std::string &Bureaucrat::getName() const {return _name;}
int Bureaucrat::getGrade() const {return _grade;}


void Bureaucrat::incrementGrade() {
    validateGrade(_grade - 1);
    _grade -= 1;
}

void Bureaucrat::decrementGrade() {
    validateGrade(_grade + 1);
    _grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << getName() << " couldn't sign " << form.getName()
            << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn't execute " << form.getName()
            << " because " << e.what() << "." << std::endl;
    }
}
