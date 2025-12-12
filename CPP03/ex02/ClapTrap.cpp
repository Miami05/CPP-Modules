#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "[ClapTrap] ctor: " << this->name
              << " (HP=" << hitPoints << ", EP=" << energyPoints
              << ", AD=" << attackDamage << ")\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name),
      hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage)
{
    std::cout << "[ClapTrap] copy-ctor: " << this->name << "\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other) {
        name         = other.name;
        hitPoints    = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "[ClapTrap] operator=: " << this->name << "\n";
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ClapTrap] dtor: " << this->name << "\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints <= 0) {
        std::cout << "[ClapTrap] " << name << " can’t attack: no HP.\n";
        return;
    }
    if (energyPoints <= 0) {
        std::cout << "[ClapTrap] " << name << " can’t attack: no energy.\n";
        return;
    }
    --energyPoints;
    std::cout << "[ClapTrap] " << name << " attacks " << target
              << ", causing " << attackDamage
              << " points of damage! (EP now " << energyPoints << ")\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0) {
        std::cout << "[ClapTrap] " << name << " is already out.\n";
        return;
    }
    int dmg = static_cast<int>(amount);
    hitPoints -= dmg;
    if (hitPoints < 0) hitPoints = 0;
    std::cout << "[ClapTrap] " << name << " takes " << dmg
              << " damage! (HP now " << hitPoints << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0) {
        std::cout << "[ClapTrap] " << name << " can’t repair: no HP.\n";
        return;
    }
    if (energyPoints <= 0) {
        std::cout << "[ClapTrap] " << name << " can’t repair: no energy.\n";
        return;
    }
    --energyPoints;
    int heal = static_cast<int>(amount);
    hitPoints += heal;
    std::cout << "[ClapTrap] " << name << " repairs " << heal
              << " HP! (HP now " << hitPoints
              << ", EP now " << energyPoints << ")\n";
}

