#include "Claptrap.hpp"
#include <iostream>

int main()
{
	ClapTrap alpha("Alpha");
	ClapTrap beta("Beta");

	std::cout << "\n --- Basic actions ---\n";
	alpha.attack("a tree");
	alpha.takeDamage(3);
	alpha.beRepaired(2);

	std::cout << "\n --- Energy exhaustion ---\n";
	for (int i = 0; i < 11; i++)
		alpha.attack("an enemy");

	std::cout << "\n --- Taking fatal damage ---\n";
	beta.takeDamage(20);
	beta.attack("Alpha");
	beta.beRepaired(5);

	std::cout << "\n --- Copy & assignment ---\n";
	ClapTrap gamma(alpha);
	ClapTrap delta("Delta");
	delta = beta;

	std::cout << "\n --- End of program ---\n";
}
