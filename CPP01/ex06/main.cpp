#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
	Harl	harl;

	if (argc != 2) {
		std::cerr << "Usage ./harlFilter <level>\n";
		return 1;
	}
	std::string level = argv[1];
	std::string levels[] = { "DEBUG",  "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	switch (i) {
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
