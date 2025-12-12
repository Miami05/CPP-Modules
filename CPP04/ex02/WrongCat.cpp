#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal()
{
	type = "Cat";
	std::cout << "[WrongCat] default ctor\n";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << "[WrongCat] copy ctor created\n";
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "[WrongCat] copy assign created\n";
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongAnimal] dtor\n";
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] meow?";
	std::cout << "(won't be called via WrongAnimal)\n";
}
