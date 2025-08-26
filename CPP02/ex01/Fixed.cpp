#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_fixedValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_fixedValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_fixedValue = other._fixedValue;
	}
	return *this;
}

float Fixed::toFloat(void) const {
	return (float)_fixedValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _fixedValue >> _fractionalBits;
}

int	Fixed::getRawBits(void) const {
	return _fixedValue;
}

void Fixed::setRawBits(int const raw) {
	_fixedValue = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}


