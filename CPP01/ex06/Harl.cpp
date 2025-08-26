#include "Harl.hpp"
#include <iostream>

void Harl::debug() {
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n\n";
}

void Harl::info() {
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n\n";
}

void Harl::warning() {
	std::cout << "[ WARNING]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years whereas you started working here last month.\n\n";
}

void Harl::error() {
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level) {
		void (Harl::*function[])() = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
		};
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*function[i])();
			return;
		}
	}
}
