
#include "Fixed.hpp"

int main( void ) {

	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "_________________subject tests_________________" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// my test
	std::cout << "_________________my tests_________________" << std::endl;
	float
	f1  = 5.6f,
	f2  = 1.125;

	const Fixed	x(f1);
	const Fixed	z(f2);
	const Fixed	y(f2);
	Fixed		w(1.5f);
	Fixed		v(3);


	std::cout << "y: " << y << std::endl;
	std::cout << "z: " << z << std::endl;

	std::cout << "_____________Arithmetic operators tests_____________" << std::endl;
	std::cout << "div: " <<  x / y << ", builtin: " <<  f1 / f2 << std::endl;
	std::cout << "mul: " <<  x * y << ", builtin: " <<  f1 * f2 << std::endl;
	std::cout << "sum: " <<  x + y << ", builtin: " <<  f1 + f2 << std::endl;
	std::cout << "sub: " <<  x - y << ", builtin: " <<  f1 - f2 << std::endl;

	std::cout << "_____________Comparison operators tests_____________" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "cmp z == y: " << (z == y) << std::endl;
	std::cout << "cmp z == x: " << (z == x) << std::endl;
	std::cout << "cmp z > y : " << (z > x) << std::endl;
	std::cout << "cmp z < y : " << (z < y) << std::endl;
	std::cout << "cmp z >= y: " << (z >= y) << std::endl;
	std::cout << "cmp z <= y: " << (z <= y) << std::endl;
	std::cout << "cmp z != y: " << (z != y) << std::endl;

	std::cout << "_____________min/max tests_____________" << std::endl;
	std::cout << "const-max: " << Fixed::max(x, y) << std::endl;
	std::cout << "const-min: " << Fixed::min(x, y) << std::endl;
	std::cout << "max: " << Fixed::max(w, v) << std::endl;
	std::cout << "min: " << Fixed::min(w, v) << std::endl;

	std::cout << "_____________increment/decrement tests_____________" << std::endl;
	Fixed c(10.5f);
	std::cout << "c: " << c << std::endl;
	std::cout << "++c: " << ++c << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c++: " << c++ << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "--c: " << --c << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "c--: " << c-- << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << "_____________toInt/toFloat tests_____________" << std::endl;
	std::cout << "x: " << x << ", toInt: " << x.toInt() << ", toFloat: " << x.toFloat() << std::endl;
	std::cout << "y: " << y << ", toInt: " << y.toInt() << ", toFloat: " << y.toFloat() << std::endl;
	std::cout << "z: " << z << ", toInt: " << z.toInt() << ", toFloat: " << z.toFloat() << std::endl;

	std::cout << "_____________end of tests_____________" << std::endl;
	return 0;
}
