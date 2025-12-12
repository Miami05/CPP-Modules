#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
class Phonebook {
	private:
	Contact contact[8];
	int contactCount;
	int oldestIndex;

	public:
	Phonebook();
	void	addContact();
	void	searchContact() const;
	void	displayContacts() const;
	bool	isValidIndex(const std::string& input, int& index) const;
};

#endif
