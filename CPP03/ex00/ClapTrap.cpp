#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructed!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints),
	attackDamage(other.attackDamage)
{
	std::cout << "Claptrap " << name << " copied\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "Claptrap " << name << " assigned\n";
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << name << " destroyed\n";
}

// Attack
void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "Claptrap " << name << " cannot attack! (No HP or energy left)\n";
		return ;
	}
	energyPoints--;
	std::cout << "Claptrap " << name << " attacks " << target << ", causing "
		<< attackDamage << " points of damage\n";
}

// Take damage
void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << "Claptrap " << name << " takes " << amount
		<< " points of damage! (HP left: "<< hitPoints << ")\n";
}

// Repair
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "Claptrap " << name << " cannot repair! (No HP or energy)\n";
		return ;
	}
	hitPoints += amount;
	energyPoints--;
	std::cout << "Claptrap " << name << " repair itself for " << amount
		<< " HP! (HP now: " << hitPoints << ")\n";
}

