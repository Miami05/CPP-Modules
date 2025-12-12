#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main() {
	Weapon club = Weapon("crude spiked club");
	HumanA bob = HumanA("Bob", club);
	bob.attack();
	club.setType("some other types of weapon");
	bob.attack();
	std::cout << std::endl;
	Weapon club1 = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club1);
	jim.attack();
	club1.setType("");
	jim.attack();
}
