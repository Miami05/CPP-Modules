
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					_fixedValue;
	static const int	_fractionalBits = 8;

public:
	// Constructors
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);

	//Destructors
	~Fixed();

	// Assignment operator
	Fixed& operator=(const Fixed& other);

	// Unary operators
	Fixed operator-() const;

	// Conversion Function
	int	toInt(void) const;
	float	toFloat(void) const;

	// Getters/Setters
	int	getRawBits(void) const;
	void setRawBits(int const raw);

	// -- Comparison operator --
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// -- Arithmetic operators --
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// -- Increment/Decrement --
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	// -- Min/Max functions --
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed& b);

};

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif
