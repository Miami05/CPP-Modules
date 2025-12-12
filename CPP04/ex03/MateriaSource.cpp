#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <cstddef>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	*this = other;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_templates[i])
			{
				delete _templates[i];
				_templates[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete _templates[i];
		_templates[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = materia->clone();
			delete materia;
			return;
		}
	}
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return 0;
}
