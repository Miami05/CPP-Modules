#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int         id;
    std::string name;
    double      score;

    Data() : id(0), name(""), score(0.0) {}
    Data(int i, const std::string &n, double s) : id(i), name(n), score(s) {}
};

#endif
