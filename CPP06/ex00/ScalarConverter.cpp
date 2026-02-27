#include "ScalarConverter.hpp"
#include <cfloat>
#include <ios>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cctype>
#include <cmath>

namespace {
    std::string trim(const std::string &s) {
        size_t b = 0;
        while (b < s.size() && (s[b] == ' ' || s[b] == '\t' || s[b] == '\n'
                    || s[b] == '\r' || s[b] == '\v' || s[b] == '\f'))
            ++b;
        size_t e = s.size();
        while (e > b && (s[e - 1] == ' ' || s[e - 1] == '\t' || s[e - 1] == '\n'
                    || s[e - 1] == '\r' || s[e - 1] == '\v' || s[e - 1] == '\f'))
            --e;
        return s.substr(b, e - b);
    }

    bool isPseudoFloat(const std::string &s) {
        return (s == "nanf" || s == "+inff" || s == "-inff");
    }

    bool isPseudoDouble(const std::string &s) {
        return (s == "nan" || s == "+inf" || s == "-inf");
    }

    bool parseInt(const std::string &s, int &out) {
        errno = 0;
        char *end = 0;
        long v = strtol(s.c_str(), &end, 10);
        if (end == s.c_str() || *end != '\0') return false;
        if (errno == ERANGE) return false;
        if (v < INT_MIN || v > INT_MAX) return false;
        out = static_cast<int>(v);
        return true;
    }

    bool parseDoubleAll(const std::string &s, double &out) {
        errno = 0;
        char *end = 0;
        double v = std::strtod(s.c_str(), &end);
        if (end == s.c_str() || *end != '\0')
            return false;
        out = v;
        return true;
    }

    bool parseFloatSuffixF(const std::string &s, double &asDouble) {
        if (s.size() < 2) return false;
        if (s[s.size() - 1] != 'f') return false;
        std::string core = s.substr(0, s.size() - 1);
        double v;
        if (!parseDoubleAll(core, v)) return false;
        asDouble = v;
        return true;
    }

    bool isSingleCharLiteral(const std::string &s) {
        return (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])));
    }

    bool isPrintableChar(int c) {
        return std::isprint(static_cast<unsigned char>(c)) != 0;
    }

    bool isNan(double x) {
        return x != x;
    }

    bool isInf(double x) {
        return (x > DBL_MAX || x < -DBL_MAX);
    }

    void printCharFromDouble(double v) {
        if (isNan(v) || isInf(v)) {
            std::cout << "char: impossible\n";
            return;
        }
        if (v < 0.0 || v > 255.0) {
            std::cout << "char: impossible\n";
            return;
        }
        int ci = static_cast<int>(v);
        if (ci < 0 || ci > 127) {
            std::cout << "char: impossible\n";
            return;
        }
        if (!isPrintableChar(ci)) {
            std::cout << "char: Non displayable\n";
            return;
        }
        std::cout << "char: '" << static_cast<char>(ci) << "'\n";
    }

    void printIntFromDouble(double v) {
        if (isNan(v) || isInf(v)) {
            std::cout << "int: impossible\n";
            return;
        }
        if (v < static_cast<double>(INT_MIN) || v > static_cast<double>(INT_MAX)) {
            std::cout << "int: impossible\n";
            return;
        }
        int iv = static_cast<int>(v);
        std::cout << "int: " << iv << "\n";
    }

    void printFloatFromDouble(double v) {
        std::cout << "float: ";
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(6);
        if (isNan(v)) {
            std::cout << "nanf\n";
            return;
        }
        if (isInf(v)) {
            if (v < 0) std::cout << "-inff\n";
            else std::cout << "+inff\n";
            return;
        }
        float fv = static_cast<float>(v);
        if (isInf(static_cast<double>(fv))) {
            if (fv < 0) std::cout << "-inff\n";
            else std::cout << "+inff\n";
            return;
        }
        double intpart;
        if (std::modf(v, &intpart) == 0.0)
            std::cout << std::fixed << std::setprecision(1) << fv << "f\n";
        else {
            std::cout.unsetf(std::ios::floatfield);
            std::cout << std::setprecision(7) << fv << "f\n";
        }
    }

    void printDoubleFromDouble(double v) {
        std::cout << "double: ";
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(6);
        if (isNan(v)) {
            std::cout << "nan\n";
            return;
        }
        if (isInf(v)) {
            if (v < 0) std::cout << "-inf\n";
            else std::cout << "+inf\n";
            return;
        }

        double intpart;
        if (std::modf(v, &intpart) == 0.0) {
            std::cout << std::fixed << std::setprecision(1) << v << "\n";
        } else {
            std::cout.unsetf(std::ios::floatfield);
            std::cout << std::setprecision(15) << v << "\n";
        }
    }

    void printAllFromDouble(double v) {
        printCharFromDouble(v);
        printIntFromDouble(v);
        printFloatFromDouble(v);
        printDoubleFromDouble(v);
    }
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) {
    std::string s = trim(literal);
    if (s.empty()) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    if (isPseudoFloat(s)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << s << "\n";
        if (s == "nanf") std::cout << "double: nan\n";
        else if (s == "+inff") std::cout << "double: +inf\n";
        else std::cout << "double: -inf\n";
        return;
    }
    if (isPseudoDouble(s)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: ";
        if (s == "nan") std::cout << "nanf\n";
        else if (s == "+inf") std::cout << "+inff\n";
        else std::cout << "-inff\n";
        std::cout << "double: " << s << "\n";
        return;
    }
    if (isSingleCharLiteral(s)) {
        char c = s[0];
        int iv = static_cast<int>(c);
        double dv = static_cast<double>(iv);
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << iv << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(dv) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1)
            << dv << "\n";
        return;
    }
    int iv;
    if (parseInt(s, iv)) {
        double dv = static_cast<double>(iv);
        printAllFromDouble(dv);
        return;
    }
    double dv;
    if (parseFloatSuffixF(s, dv)) {
        printAllFromDouble(dv);
        return;
    }
    if (parseDoubleAll(s, dv)) {
        printAllFromDouble(dv);
        return;
    }
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}
