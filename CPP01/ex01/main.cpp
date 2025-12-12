#include "Zombie.hpp"
#include <iostream>
#include <string>

int main() {
	int hordeSize;
	std::cout << "Enter the number of zombies you want to create: ";
	std::cin >> hordeSize;
	Zombie* horde = zombieHorde(hordeSize, "HordeDude");
	if (!horde)
		return 1;
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
	delete [] horde;
}
