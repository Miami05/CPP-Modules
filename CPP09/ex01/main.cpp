#include "RPN.hpp"
#include <string>

int main(int ac, char **av) {
    if (ac != 2) {
        return RPN::evaluate("");
    }
    return RPN::evaluate(av[1]);
}
