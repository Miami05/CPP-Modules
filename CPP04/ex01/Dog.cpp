#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), brain(new Brain())
{
	type = "Dog";
	std::cout << "[Dog] default ctor\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "[Dog] copy ctor (deep)\n";
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] copy assign (deep)\n";
	if (this != &other)
	{
		Animal::operator=(other);
		Brain* fresh = new Brain(*other.brain);
		delete brain;
		brain = fresh;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] default dtor\n";
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] woof\n";
}

void Dog::setIdea(int idx, const std::string& s)
{
	brain->setIdea(idx, s);
}

const std::string& Dog::getIdea(int idx) const
{
	return brain->getIdea(idx);
}
