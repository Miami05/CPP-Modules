#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "[ScavTrap] created: " << this->name
		<< " (HP=" << hitPoints << ", EP=" << energyPoints << ", AD=" << attackDamage << ")\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "[ScavTrap] copy-created: " << this->name << "\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "[ScavTrap] operator=: " << this->name << "\n";
	return *this;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "[ScavTrap] dtor: " << this->name << "\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "[ScavTrap] " << name << " can't attack: no HP.\n";
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "[ScavTrap] " << name << " can't attack: no energy.\n";
		return;
	}
	--energyPoints;
	std::cout << "[ScavTrap] " << name << " ambushes " << target
		<< " for " << attackDamage << " damage! (EP now " << energyPoints << ")\n";
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] " << name << " is now in Gate keeper mode!\n";
}
