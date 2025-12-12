#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	hitPoints     = 100;
	energyPoints  = 50;
	attackDamage  = 30;
	std::cout << "[DiamondTrap] ctor: " << this->name << " (ClapTrap name=" << ClapTrap::name
		<< ", HP=" << hitPoints << ", EP=" << energyPoints << ", AD=" << attackDamage << ")\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other),
FragTrap(other), name(other.name)
{
	std::cout << "[DiamondTrap] operator=: " << this->name << "\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	std::cout << "[DiamondTrap] operator=: " << this->name << "\n";
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] dtor: " << this->name << "\n";
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap] My name is " << name
		<< " and my ClapTrap name is " << ClapTrap::name << "\n";
}
