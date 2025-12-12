#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() 
{
	type = "Cat";
	std::cout << "[Cat] is created\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "[Cat] copy ctor is created\n";
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] copy assign ctor is created\n";
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat] dtor is created\n";
}

void Cat::makeSound() const
{
	std::cout << "[Cat] Meow\n";
}
