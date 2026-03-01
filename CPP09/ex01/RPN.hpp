#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
private:
    RPN();
    RPN(const RPN&);
    RPN& operator=(const RPN&);
    ~RPN();

    static bool isOperatorToken(const std::string& t);
    static bool isDigitToken(const std::string& t);

public:
    static int evaluate(const std::string& expr);
};

#endif
