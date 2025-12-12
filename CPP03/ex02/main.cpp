#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n=== Construction order demo===\n";
	ScavTrap scav("Serena");
	FragTrap frag("Bubbles");

	std::cout << "\n=== ScavTrap actions ===\n";
	scav.attack("an intruder");
	scav.guardGate();
	scav.takeDamage(35);
	scav.beRepaired(20);

	std::cout << "\n=== FragTrap actions ===\n";
	frag.attack("a dummy");
	frag.highFiveGuys();
	frag.takeDamage(60);
	frag.beRepaired(40);

	std::cout << "\n=== copy & assignment ===\n";
	FragTrap copyFrag(frag);
	FragTrap otherFrag("Temp");
	otherFrag = frag;
	std::cout << "\n=== Destruction order on scope exit ===\n";
}
