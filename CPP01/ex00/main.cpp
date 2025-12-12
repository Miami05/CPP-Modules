#include "Zombie.hpp"

int main()
{
	Zombie* heapName = newZombie("HeapGuy");
	heapName->announce();
	delete heapName;

	randomChump("Stack Zombie");
}
