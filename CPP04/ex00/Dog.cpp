#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "[Dog] default ctor\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "[Dog] copy ctor\n";
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] copy assign\n";
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] default dtor\n";
}

void Dog::makeSound() const
{
	std::cout << "[Dog] woof\n";
}
