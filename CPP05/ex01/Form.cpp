#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
        validateGrade(_gradeToSign);
        validateGrade(_gradeToExecute);
}

Form::Form(const Form &other)
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form() {}

void Form::validateGrade(int grade) const {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const std::string &Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

const char *Form::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "grade too low";
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooHighException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
    os << "Form{name =" << f.getName() << ", signed="
        << (f.isSigned() ? "true" : "false") << ", gradeToSign=" << f.getGradeToSign()
        << ", gradeToExecute=" << f.getGradeToExecute() << "}";
    return os;
}
