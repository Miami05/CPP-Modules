#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "==== Construction order demo ===\n";
	ScavTrap serena("Serena");

	std::cout << "\n=== ScavTrap actions ===\n";
	serena.attack("an intruder");
	serena.guardGate();
	serena.takeDamage(35);
	serena.beRepaired(20);

	std::cout << "\n=== Copy & assignment ===\n";
	ScavTrap copy(serena);
	ScavTrap other("other");
	other = serena;

	std::cout << "\n=== Base Claptrap still work\n";
	ClapTrap c("Basic");
	c.attack("a dummy");
	c.takeDamage(5);
	c.beRepaired(3);
	std::cout << "\n=== Destruction order on scope exit ===\n";
}
