#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints    = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "[FragTrap] is created: " << this->name
		<< " (HP=" << hitPoints << ", EP=" << energyPoints
		<< ", AD=" << attackDamage << ")\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "[FragTrap] copy-ctor is created: " << this->name << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "[FragTrap] operator=: " << this->name << "\n";
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] dtor is created: " << this->name << "\n";
}

void FragTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "[FragTrap] " << name << " can't attact: no HP\n";
		return;
	}
	if (energyPoints <= 0)
	{
		std::cout << "[FragTrap] " << name << " can't attack: no EP\n";
		return;
	}
	--energyPoints;
	std::cout << "[FragTrap] " << name << " blasts " << target
		<< " for " << attackDamage << " damage! (EP=" << energyPoints << ")\n";
}

void FragTrap::highFiveGuys()
{
	std::cout << "[FragTrap] " << name << " requests high fives! ✋\n";
}
