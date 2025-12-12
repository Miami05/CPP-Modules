#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("Unnamed") {}

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
