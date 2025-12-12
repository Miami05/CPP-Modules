#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	AMateria*	_templates[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource const & other);
	MateriaSource & operator=(MateriaSource const & other);
	~MateriaSource();
	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
