#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
private:
    typedef AForm *(*CreateFn)(const std::string &target);
    static AForm *createShrubbery(const std::string &target);
    static AForm *createRobotomy(const std::string &target);
    static AForm *createPresidential(const std::string &target);

public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(const std::string &name, const std::string &target);
};

#endif 
