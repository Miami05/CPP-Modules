#include "Point.hpp"

int main() {
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point p1(1, 1);
	Point p2(0, 0);
	Point p3(6, 6);

	std::cout << "p1 inside is = " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2 vertex is = " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3 outside is = " << bsp(a, b, c, p3) << std::endl;
}
