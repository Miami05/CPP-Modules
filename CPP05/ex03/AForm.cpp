#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute,
        const std::string &target)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), 
    _gradeToExecute(gradeToExecute), _target(target) {
        validateGrade(_gradeToSign);
        validateGrade(_gradeToExecute);
}

AForm::AForm(const AForm &other)
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute), _target(other._target) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {}

void AForm::validateGrade(int grade) const {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }
const std::string &AForm::getTarget() const { return _target; }

const char *AForm::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "form not signed";
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooHighException();
    _signed = true;
}


void AForm::execute(Bureaucrat const &executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
    os << "AForm{name =" << f.getName() << ", signed="
        << (f.isSigned() ? "true" : "false") << ", gradeToSign=" << f.getGradeToSign()
        << ", gradeToExecute=" << f.getGradeToExecute() 
        << ", target=" << f.getTarget() << "}";
    return os;
}
