#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "[Brain] default ctor\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
	std::cout << "[Brain] copy ctor\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "[Brain] copy assign\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "[Brain] dtor\n";
}

void Brain::setIdea(int idx, const std::string& value)
{
	if (idx >= 0 && idx < 100)
		ideas[idx] = value;
}

const std::string& Brain::getIdea(int idx) const
{
	static const std::string empty = "";
	if (idx >= 0 && idx < 100)
		return ideas[idx];
	return empty;
}
