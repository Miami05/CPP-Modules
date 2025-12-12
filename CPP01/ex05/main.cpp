#include <iostream>
#include "Harl.hpp"

int main() {
	Harl	h;

	std::cout << "== Known Levels ==\n";
	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");

	std::cout << "\n== Unknown level ==\n";
	h.complain("VERBOSE");
}
