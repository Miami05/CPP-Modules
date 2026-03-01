#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <stdexcept>
#include <cmath>

BitcoinExchange::BitcoinExchange()  {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) _rates = other._rates;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

static bool isDigits(const std::string& s) {
    if (s.empty()) return false;
    for (std::size_t i = 0; i < s.size(); ++i)
        if (s[i] < '0' || s[i] > '9') return false;
    return true;
}

std::string BitcoinExchange::trim(const std::string& s) {
    std::size_t b = 0;
    while (b < s.size() && (s[b] == ' ' || s[b] == '\t' || s[b] == '\r' || s[b] == '\n'))
        ++b;
    std::size_t e = s.size();
    while (e > b && (s[e - 1] == ' ' || s[e - 1] == '\t' || s[e - 1] == '\r' || s[e - 1] == '\n'))
        --e;
    return s.substr(b, e - b);
}

static bool isLeap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return (y % 4 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.size() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    std::string ys = date.substr(0, 4);
    std::string ms = date.substr(5, 2);
    std::string ds = date.substr(8, 2);
    if (!isDigits(ys) || !isDigits(ms) || !isDigits(ds)) return false;
    int y = std::atoi(ys.c_str());
    int m = std::atoi(ms.c_str());
    int d = std::atoi(ds.c_str());
    if (y < 0) return false;
    if (m < 1 || m > 12) return false;
    int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int maxd = mdays[m - 1];
    if (m == 2 && isLeap(y)) maxd = 29;
    if (d < 1 || d > maxd) return false;
    return true;
}

bool BitcoinExchange::parseValue(const std::string& token, double& out) {
    std::string t = trim(token);
    if (t.empty()) return false;
    errno = 0;
    char* end = 0;
    double v = std::strtod(t.c_str(), &end);
    if (end == t.c_str() || *end != '\0') return false;
    if (errno == ERANGE) {
        if (v == HUGE_VAL || v == -HUGE_VAL) {
            out = 1001.0;
            return true;
        }
    }
    out = v;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& csvPath) {
    std::ifstream f(csvPath.c_str());
    if (!f.is_open())
        throw std::runtime_error("Error: could not open database");
    std::string line;
    if (!std::getline(f, line))
        throw std::runtime_error("Error: empty database");
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        std::size_t comma = line.find(',');
        if (comma == std::string::npos) continue;
        std::string date = trim(line.substr(0, comma));
        std::string rateS = trim(line.substr(comma + 1));
        if (!isValidDate(date)) continue;
        double rate;
        if (!parseValue(rateS, rate)) continue;
        _rates[date] = rate;
    }
    if (_rates.empty())
        throw std::runtime_error("Error: database has no valid entries.");
}


bool BitcoinExchange::getRateForDate(const std::string& date, double& outRate) const {
    std::map<std::string, double>::const_iterator it = _rates.find(date);
    if (it != _rates.end()) {
        outRate = it->second;
        return true;
    }
    it = _rates.lower_bound(date);
    if (it == _rates.begin()) {
        return false;
    }
    if (it == _rates.end()) {
        std::map<std::string, double>::const_iterator last = _rates.end();
        --last;
        outRate = last->second;
        return true;
    }
    --it;
    outRate = it->second;
    return true;
}

void BitcoinExchange::processFile(const std::string& inputPath) {
    loadDatabase("data.csv");
    std::ifstream in(inputPath.c_str());
    if (!in.is_open()) {
        std::cout << "Error: could not open file.\n";
        return;
    }
    std::string line;
    bool firstNonEmptyLine = true;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        if (firstNonEmptyLine) {
            firstNonEmptyLine = true;
            if (trim(line) == "date | value")
                continue;
        }
        std::size_t bar = line.find('|');
        if (bar == std::string::npos) {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }
        std::string date = trim(line.substr(0, bar));
        std::string valueToken = trim(line.substr(bar + 1));
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << "\n";
            continue;
        }
        double value;
        if (!parseValue(valueToken, value)) {
            std::cout << "Error: bad input => " << date << "\n";
            continue;
        }
        if (value < 0.0) {
            std::cout << "Error: not a positive number.\n";
            continue;
        }
        if (value > 1000.0) {
            std::cout << "Error: too large a number.\n";
            continue;
        }
        double rate;
        if (!getRateForDate(date, rate)) {
            std::cout << "Error: bad input => " << date << "\n";
            continue;
        }
        double result = value * rate;
        std::cout << date << " => " << valueToken << " = " << result << "\n";
    }
}
