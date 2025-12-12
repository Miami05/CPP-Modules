#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain())
{
	type = "Cat";
	std::cout << "[Cat] is created\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "[Cat] copy ctor is created (deep)\n";
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] copy assign ctor is created\n";
	if (this != &other)
	{
		Animal::operator=(other);
		Brain* fresh = new Brain(*other.brain);
		delete brain;
		brain = fresh;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat] dtor is created\n";
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] Meow\n";
}

void Cat::setIdea(int idx, const std::string& s)
{
	brain->setIdea(idx, s);
}

const std::string& Cat::getIdea(int idx) const
{
	return brain->getIdea(idx);
}
