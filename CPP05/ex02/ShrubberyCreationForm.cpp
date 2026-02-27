#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreatingForm", 145, 137, target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    const std::string filename = getTarget() + "_shrubbery";
    std::ofstream out(filename.c_str());
    if (!out.is_open())
        return;
    out << "       _-_\n";
	out << "    /~~   ~~\\\n";
	out << " /~~         ~~\\\n";
	out << "{               }\n";
	out << " \\  _-     -_  /\n";
	out << "_- -   | | _- _\n";
	out << "  _ -  | |   -_\n";
	out << "      // \\\\\n";
}
