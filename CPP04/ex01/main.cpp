#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
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
	delete dog;
	delete cat;

	seperator("Array of Animals (half Dog, half Cat)");
	const int N = 10;
	Animal* zoo[N];
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}
	for (int i = 0; i < N; i++)
		zoo[i]->makeSound();
	for (int i = 0; i < N; i++)
		delete zoo[i];
	seperator("Deep copy Dog");
	Dog a;
	a.setIdea(0, "Chase the mailman");
	Dog b = a;
	a.setIdea(0, "Chew the ball");
	std::cout << "a[0] = " << a.getIdea(0) << std::endl;
	std::cout << "b[0] = " << b.getIdea(0) << std::endl;
	seperator("Deep copy test (Cat)");
	Cat c1;
	c1.setIdea(0, "Nap on the keyboard");
	Cat c2;
	c2 = c1;
	c1.setIdea(0, "Drinking water");
	std::cout << "c1[0] = " << c1.getIdea(0) << std::endl;
	std::cout << "c2[0] = " << c2.getIdea(0) << std::endl;
	seperator("Wrong hierarchy demo");
	const WrongAnimal* wa = new WrongCat();
	wa->makeSound();
	delete wa;
}
