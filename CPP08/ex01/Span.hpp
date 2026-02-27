#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span {
private:
    unsigned int       _capacity;
    std::vector<int>   _v;
public:
    class FullException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class NotEnoughNumbersException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(int n);
    template <typename  It>
    void addNumber(It first, It last) {
        for (; first != last; ++first) {
            if (_v.size() >= _capacity)
                throw FullException();
            _v.push_back(*first);
        }
    }
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    unsigned int capacity() const;
    std::size_t  size() const;
};

#endif
