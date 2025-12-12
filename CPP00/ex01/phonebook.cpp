#include "phonebook.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>

Phonebook::Phonebook() {
	contactCount = 0;
	oldestIndex = 0;
}

void Phonebook::addContact() {
	Contact new_contact;

	std::cout << "\n-- Adding New Contact ---" << std::endl;
	if (!new_contact.setContact()) {
		std::cout << "Failed to add contact due to invalid input." << std::endl;
		return ;
	}
	if (contactCount < 8) {
		contact[contactCount] = new_contact;
		contactCount++;
	} else {
		contact[oldestIndex] = new_contact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
	std::cout << "Contact successfully added!" << std::endl;
}

void Phonebook::displayContacts() const {
	std::cout << std::setw(10) << std::right << "Index" << "|"
	<< std::setw(10) << std::right << "First Name" << "|"
	<< std::setw(10) << std::right << "Last Name" << "|"
	<< std::setw(10) << std::right << "Nickname" << std::endl;
	std::cout << "-------------------------------------------|" << std::endl;
	for (int i = 0; i < contactCount; i++) {
		contact[i].displaySummary(i);
	}
}

bool Phonebook::isValidIndex(const std::string& input, int& index) const {
	if (input.empty())
		return false;
	for (size_t i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			return false;
		}
	}
	std::stringstream ss(input);
	ss >> index;
	if (index < 0 || index >= contactCount)
		return false;
	return true;
}

void Phonebook::searchContact() const {
	if (contactCount == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	std::cout << "\n--- Contact List ---" << std::endl;
	displayContacts();
	std::string input;
	int index;
	std::cout << "\nEnter the index of the contact to display: ";
	if (!std::getline(std::cin,input)) {
		std::cout << "\nInput interrupted. Search canceled." << std::endl;
		return ;
	}
	if (!isValidIndex(input, index)) {
		std::cout << "Invalid index. Please enter a number between 0 and 8." << std::endl;
		return ;
	}
	std::cout << "\n--- Contact Details ---" << std::endl;
	contact[index].displayFull();
}
