#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array {
private:
    T*          _data;
    std::size_t _size;
public:
    class OutOfBounds : public std::exception {
        public:
            virtual const char* what() const throw() { return "Array: index out of bonds"; }
    };

    Array(): _data(0), _size(0) {}

    Array(std::size_t n) : _data(0), _size(n) {
        if (_size == 0) return;
        _data = new T[_size];
    }

    Array(const Array& other) : _data(0), _size(other._size) {
        if (_size == 0) return;
        _data = new T[_size];
        for (std::size_t i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }

    Array& operator=(const Array& other) {
        if (this == &other) return *this;
        T* newData = 0;
        if (other._size != 0) {
            newData = new T[other._size];
            for (std::size_t i = 0; i < other._size; ++i)
                newData[i] = other._data[i];
        }
        delete[] _data;
        _data = newData;
        _size = other._size;
        return *this;
    }

    ~Array() { delete[] _data; }

    std::size_t size() const { return _size; }

    T& operator[](std::size_t index) {
        if (index >= _size) throw OutOfBounds();
        return _data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= _size) throw OutOfBounds();
        return _data[index];
    }
};
#endif
