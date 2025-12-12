#include "Animal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Right Hierarchy ===\n";
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "The type is: " << dog->getType() << std::endl;
	std::cout << "The type is: " << cat->getType() << std::endl;

	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete cat;
	delete dog;
	delete meta;

	std::cout << "\n=== Wrong Hierarchy (no virtual)===\n";
	const WrongAnimal *wanimal = new WrongAnimal();
	const WrongAnimal *wcat = new WrongCat();

	std::cout << wcat->getType() << std::endl;

	wcat->makeSound();
	wanimal->makeSound();

	delete wcat;
	delete wanimal;

	std::cout << "\n=== Direct call on WrongCat (works but no polymorphism) ===\n";
	WrongCat wc;
	wc.makeSound();
}
