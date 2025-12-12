#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal") {
	std::cout << "[Animal] default ctor\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "[Animal] copy ctor\n";
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "[Animal] copy assign ctor\n";
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "[Animal] dtor\n";
}

const std::string& Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "[Animal] (general silence)\n";
}
