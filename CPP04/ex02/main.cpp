#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

static void seperator(const std::string& title)
{
	std::cout << "\n---- " << title << " ----\n";
}

int main()
{
	seperator("Simple Dog and Cat creation & deletion");
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	cat->makeSound();
	dog->makeSound();
	delete dog;
	delete cat;
}
