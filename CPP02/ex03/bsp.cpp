#include "Point.hpp"

Fixed ft_abs(Fixed const &f) {
	if (f < Fixed(0))
		return -f;
	return f;
}

Fixed triangleArea(Point const p1, Point const p2, Point const p3) {
	Fixed area = ((p1.getX() * (p2.getY() - p3.getY())) 
		+ (p2.getX() * (p3.getY() - p1.getY())) + (p3.getX() * (p1.getY() - p2.getY()))) / Fixed(2);
	return ft_abs(area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = triangleArea(a, b, c);
	Fixed A1 = triangleArea(point, b, c);
	Fixed A2 = triangleArea(a, point, c);
	Fixed A3 = triangleArea(a, b, point);

	if (A1 == 0 || A2 == 0 || A3 == 0)
		return false;
	return (A == (A1 + A2 + A3));
}
