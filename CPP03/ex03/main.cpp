#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n=== DiamondTrap demo ===\n";
	DiamondTrap d("Shiny");

	d.attack("target");
	d.highFiveGuys();
	d.guardGate();
	d.whoAmI();
	d.takeDamage(44);
	d.beRepaired(20);
	std::cout << "\n=== Copy & assignment ===\n";
	DiamondTrap copy(d);
	DiamondTrap other("Other");
	other = d;
	std::cout << "\n=== Destruction order on scope exit ===\n";
}
