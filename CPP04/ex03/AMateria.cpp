#include "AMateria.hpp"
#include <string>

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const & other) : _type(other._type) {}

AMateria::~AMateria() {}

AMateria & AMateria::operator=(AMateria const & other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& /*target*/) {}
