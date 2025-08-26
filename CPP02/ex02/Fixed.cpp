#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {}

Fixed::Fixed(const int value) {
	_fixedValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_fixedValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (&other != this) {
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

int Fixed::getRawBits(void) const {
	return _fixedValue;
}

void Fixed::setRawBits(int const raw) {
	_fixedValue = raw;
}

bool Fixed::operator>(const Fixed& other) const { return _fixedValue > other._fixedValue; }
bool Fixed::operator<(const Fixed& other) const { return _fixedValue < other._fixedValue; }
bool Fixed::operator>=(const Fixed& other) const { return _fixedValue >= other._fixedValue; }
bool Fixed::operator<=(const Fixed& other) const { return _fixedValue <= other._fixedValue; }
bool Fixed::operator==(const Fixed& other) const { return _fixedValue == other._fixedValue; }
bool Fixed::operator!=(const Fixed& other) const { return _fixedValue != other._fixedValue; }

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	_fixedValue++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_fixedValue++;
	return (temp);
}

Fixed& Fixed::operator--() {
	_fixedValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_fixedValue--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
