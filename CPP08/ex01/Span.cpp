#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <limits.h>
#include <limits>
#include <vector>

const char* Span::FullException::what() const throw() {
    return "Span: container is full";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
    return "Span: not enough numbers to compute span";
}

Span::Span() : _capacity(0), _v() {}

Span::Span(unsigned int N) : _capacity(N), _v() {
    _v.reserve(N);
}

Span::Span(const Span& other) : _capacity(other._capacity), _v(other._v) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _capacity = other._capacity;
        _v = other._v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_v.size() >= _capacity)
        throw FullException();
    _v.push_back(n);
}

unsigned int Span::shortestSpan() const {
    if (_v.size() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> tmp(_v);
    std::sort(tmp.begin(), tmp.end());
    unsigned int best = std::numeric_limits<unsigned int>::max();
    for (std::size_t i = 1; i < tmp.size(); ++i) {
        long diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
        if (diff < 0) diff = -diff;
        if (static_cast<unsigned long>(diff) < best)
            best = static_cast<unsigned int>(diff);
    }
    return best;
}

unsigned int Span::longestSpan() const {
    if (_v.size() < 2)
        throw NotEnoughNumbersException();
    int mn = *std::min_element(_v.begin(), _v.end());
    int mx = *std::max_element(_v.begin(), _v.end());
    long diff = static_cast<long>(mx) - static_cast<long>(mn);
    if (diff < 0) diff = -diff;
    return static_cast<unsigned int>(diff);
}

unsigned int Span::capacity() const { return _capacity; }
std::size_t  Span::size() const { return _v.size(); }
