#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(float const x_val, float const y_val);
	Point(Point const &other);
	Point &operator=(Point const &other);
	~Point();
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif

