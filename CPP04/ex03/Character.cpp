#include "Character.hpp"
#include <cstddef>

Character::Character(std::string const & name) : _name(name), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
	for (int i = 0; i < 32; i++)
		_floor[i] = NULL;
}

Character::Character(Character const & other) : _name(other._name), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
	for (int i = 0; i < 32; i++)
		_floor[i] = NULL;
	cloneFrom(other);
}

Character & Character::operator=(Character const & other)
{
	if (this != &other)
	{
		_name = other._name;
		clearInventory();
		cloneFrom(other);
	}
	return *this;
}

Character::~Character()
{
	clearInventory();
	for (int i = 0; i < _floorCount; i++)
	{
		delete _floor[i];
		_floor[i] = NULL;
	}
}

void Character::clearInventory()
{
	for (int i = 0; i < 4; i++)
	{
		delete _inv[i];
		_inv[i] = NULL;
	}
}

void Character::cloneFrom(Character const & other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inv[i])
			_inv[i] = other._inv[i]->clone();
		else
			_inv[i] = NULL;
	}
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inv[i] == NULL)
		{
			_inv[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
		return;
	if (_inv[idx] == NULL)
		return;
	if (_floorCount < 32)
		_floor[_floorCount++] = _inv[idx];
	_inv[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return;
	if (_inv[idx] == NULL)
		return;
	_inv[idx]->use(target);
}
