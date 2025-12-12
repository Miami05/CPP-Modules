#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout
	<< "[ DEBUG ]\n"
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-"
	"special-ketchup burger. I really do!\n";
}

void	Harl::info(void) {
	std::cout
	<< "[ INFO ]\n"
	<< "I cannot believe adding extra bacon costs more money."
	<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
}

void	Harl::warning(void) {
	std::cout
	<< 
		"\n[ WARNING ]\n"
	<< "I think I deserve to have some extra bacon for free."
	<< "I’ve been coming for years, whereas you started working here just last month.";
}

void	Harl::error(void) {
	std::cout
	<< "\n[ ERROR ]\n"
	<< "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level) {
	static const Entry table[] = {
		{ "DEBUG", &Harl::debug },
		{ "INFO", &Harl::info },
		{ "WARNING", &Harl::warning },
		{ "ERROR", &Harl::error }
	};
	for (size_t i = 0; i < sizeof(table) / sizeof(table[0]); i++)
	{
		if (level == table[i].name)
		{
			(this->*table[i].fn)();
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problem ]\n";
}
