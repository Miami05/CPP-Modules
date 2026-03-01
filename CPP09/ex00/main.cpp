#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **argv) {
    if (ac != 2) {
        std::cout << "Error: could not open the file.\n";
        return 1;
    }
    try {
        BitcoinExchange btc;
        btc.processFile(argv[1]);
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
        return 1;
    }
    return 0;
}
