#include "phonebook.hpp"
#include <iostream>
#include <string>
#include <csignal>
#include <cstdlib>

void signalHandler(int signal) {
	std::cout << signal << std::endl;
	std::exit(0);
}

std::string	to_lower(const std::string& str)
{
	std::string lower = str;
	for (size_t i = 0; i < lower.length(); i++)
		lower[i] = std::tolower(static_cast<unsigned char>(lower[i]));
	return lower;
}

int main() {
	Phonebook phonebook;
	std::string command;

	std::signal(SIGINT, signalHandler);
	std::signal(SIGQUIT, signalHandler);
	std::signal(SIGTERM, signalHandler);
	std::cout << "=== Welcome to the Phonebook ===" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	std::cout << "Press Ctrl+C, Ctrl+D or type EXIT to quit" << std::endl;
	while (true) {
		std::cout << "\nEnter a command: ";
		if (!std::getline(std::cin, command)) {
			std::cout << "\nEOF detected (CTR+D). Exiting..." << std::endl;
			break;
		}
		std::string cmdToLower = to_lower(command);
		if (cmdToLower == "add") {
			phonebook.addContact();
		}
		else if (cmdToLower == "search") {
			phonebook.searchContact();
		}
		else if (cmdToLower == "exit") {
			std::cout << "Goodbye! All contacts will be lost." << std::endl;
			break;
		}
		else {
			std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT" << std::endl;
		}
	}
	return 0;
}
