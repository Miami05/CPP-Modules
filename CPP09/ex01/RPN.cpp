#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

RPN::RPN() {}
RPN::RPN(const RPN&) {}
RPN& RPN::operator=(const RPN&) { return *this; }
RPN::~RPN() {}

bool RPN::isOperatorToken(const std::string& t) {
    return (t.size() == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/'));
}

bool RPN::isDigitToken(const std::string& t) {
    return (t.size() == 1 && t[0] >= '0' && t[0] <= '9');
}

int RPN::evaluate(const std::string &expr) {
    std::istringstream iss(expr);
    std::stack<long> st;
    std::string tok;
    while (iss >> tok) {
        if (isDigitToken(tok))
            st.push(tok[0] - '0');
        else if (isOperatorToken(tok)) {
            if (st.size() < 2) {
                std::cerr << "Error\n";
                return 1;
            }
            long b = st.top(); st.pop();
            long a = st.top(); st.pop();
            long r = 0;
            switch (tok[0]) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;
                case '/':
                    if (b == 0) {
                        std::cerr << "Error\n";
                        return 1;
                    }
                    r = a / b;
                    break;
            }
            st.push(r);
        }
        else {
            std::cerr << "Error\n";
            return 1;
        }
    }
    if (st.size() != 1) {
        std::cerr << "Error\n";
        return 1;
    }
    std::cout << st.top() << "\n";
    return 0;
}
