/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurmish < ldurmish@student.42wolfsburg.d  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 23:29:44 by ldurmish          #+#    #+#             */
/*   Updated: 2025/09/06 00:05:49 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character: public ICharacter
{
private:
	std::string		_name;
	AMateria*		_inv[4];
	AMateria*		_floor[32];
	int				_floorCount;
	void			clearInventory();
	void			cloneFrom(Character const & other);
public:
	Character(std::string const & name);
	Character(Character const & other);
	Character & operator=(Character const & other);
	virtual ~Character();
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
