#include "contact.hpp"
#include <iomanip>
#include <iostream>
#include <cctype>
#include <ostream>
#include <string>

static bool isOnlyWhitespace(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!isspace(str[i]))
			return false;
	}
	return true;
}

static bool containsDigit(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (isdigit(str[i]))
			return true;
	}
	return false;
}

static bool isValidPhoneNumber(const std::string& number) {
	if (number.empty())
		return false;
	bool has_digit = false;
	for (size_t i = 0; i < number.length(); i++) {
		char c = number[i];
		if (i == 0 && c == '+')
			continue;
		if (c == ' ')
			continue;
		if (isdigit(c)) {
			has_digit = true;
			continue;
		}
		return false;
	}
	return has_digit;
}

bool Contact::setContact() {
	std::string	input;

	while (true){
		std::cout << "Enter First Name: ";
		std::getline(std::cin, input);
		if (input.empty() || isOnlyWhitespace(input))
			std::cout << "Invalid input: First name cannot be empty or just spaces" << std::endl;
		else if (containsDigit(input))
			std::cout << "Invalid input: First name cannot contain digit." << std::endl;
		else {
			this->firstName = input;
			break;
		}
	}
	while (true) {
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, input);
		if (input.empty() || isOnlyWhitespace(input))
			std::cout << "Invalid input: Last name cannot be empty or just spaces" << std::endl;
		else if (containsDigit(input))
			std::cout << "Invalid input: Last name cannot contain digit." << std::endl;
		else {
			this->lastName = input;
			break;
		}
	}
	while (true) {
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, input);
		if (input.empty() || isOnlyWhitespace(input))
			std::cout << "Invalid input: Nickname cannt be empty or just spaces" << std::endl;
		else {
			this->nickname = input;
			break;
		}
	}
	while (true) {
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, input);
		if (!isValidPhoneNumber(input))
			std::cout << "Invalid input: Phone number must contain only digit, space and optionally start with '+'" << std::endl;
		else {
			this->phoneNumber = input;
			break;
		}
	}
	while (true) {
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Invalid input: Darkest Secret cannot be empty";
		else {
			this->darkestSecret = input;
			break;
		}
	}
	return true;
}

std::string formatField(const std::string &str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::displaySummary(int index) const {
	std::cout << std::setw(10) << std::right << index << "|"
	<< std::setw(10) << std::right << formatField(this->firstName) << "|"
	<< std::setw(10) << std::right << formatField(this->lastName) << "|"
	<< std::setw(10) << formatField(this->nickname) << std::endl;
}

void Contact::displayFull() const {
	std::cout << "Enter First Name  : " << this->firstName << std::endl;
	std::cout << "Enter Last Name   : " << this->lastName << std::endl;
	std::cout << "Nickname          : " << this->nickname << std::endl;
	std::cout << "Phone number      : " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret    : " << this->darkestSecret << std::endl;
}

bool Contact::isEmpty() const {
	return firstName.empty();
}
