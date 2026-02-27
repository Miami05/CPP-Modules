#ifndef AFORM_HPP
#define AFORM_HPP

#include <ostream>
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
    const std::string _target;

    void validateGrade(int grade) const;

protected:
    virtual void executeAction() const = 0;

public:
    AForm(const std::string &name, int gradeToSign, int gradeToExecute,
            const std::string &target);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string &getTarget() const;

    void beSigned(Bureaucrat const &b);
    void execute(Bureaucrat const &executor) const;

    class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
        public:
            const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
