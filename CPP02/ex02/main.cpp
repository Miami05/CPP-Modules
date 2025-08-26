#include "Fixed.hpp"

int main() {
    std::cout << "=== Arithmetic Tests ===" << std::endl;
    Fixed x(5.5f);
    Fixed y(2);

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;

    std::cout << "\n=== Comparison Tests ===" << std::endl;
    std::cout << "x > y  ? " << (x > y) << std::endl;
    std::cout << "x < y  ? " << (x < y) << std::endl;
    std::cout << "x >= y ? " << (x >= y) << std::endl;
    std::cout << "x <= y ? " << (x <= y) << std::endl;
    std::cout << "x == y ? " << (x == y) << std::endl;
    std::cout << "x != y ? " << (x != y) << std::endl;

    std::cout << "\n=== Increment/Decrement Tests ===" << std::endl;
    Fixed z;
    std::cout << "z = " << z << std::endl;
    std::cout << "++z = " << ++z << " (pre-increment)" << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "z++ = " << z++ << " (post-increment)" << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "--z = " << --z << " (pre-decrement)" << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "z-- = " << z-- << " (post-decrement)" << std::endl;
    std::cout << "z = " << z << std::endl;

    std::cout << "\n=== Min/Max Tests ===" << std::endl;
    Fixed a(3.3f);
    Fixed b(7.7f);

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << Fixed::min(a, b)<< std::endl;
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

    const Fixed c(10);
    const Fixed d(42.42f);

    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;

    return 0;
}

