#include "Fixed.hpp"

int main( void ) {
	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );

	a = Fixed( 1234.4321f );
	std::cout << "_________________subject tests_________________" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// my test
	std::cout << "_________________my tests_________________" << std::endl;
	float
	f1  = 5.6f,
	f2  = 1.125f,
	f3  = 10.625f;

	std::cout << "_____________ toInt tests _____________" << std::endl;
	std::cout << "f1: " << f1 << ", toInt: " << Fixed(f1).toInt() << std::endl;
	std::cout << "f2: " << f2 << ", toInt: " << Fixed(f2).toInt() << std::endl;
	std::cout << "f3: " << f3 << ", toInt: " << Fixed(f3).toInt() << std::endl;

	std::cout << "_____________ toFloat tests _____________" << std::endl;
	std::cout << "f1: " << f1 << ", toFloat: " << Fixed(f1).toFloat() << std::endl;
	std::cout << "f2: " << f2 << ", toFloat: " << Fixed(f2).toFloat() << std::endl;
	std::cout << "f3: " << f3 << ", toFloat: " << Fixed(f3).toFloat() << std::endl;


	return 0;
}
