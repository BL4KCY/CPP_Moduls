#include "Point.hpp"

int main( void ) {

	const Point a(1, 1);
	const Point b(5, 1);
	const Point c(3, 4);

	// insde
	const Point P1(3, 2);
	// outside
	const Point P2 (6, 3);
	// example p is outside.
	std::cout << std::boolalpha;
	std::cout << "is P1: " <<  bsp(a, b, c, P1) << std::endl;
	std::cout << "is P2: " <<  bsp(a, b, c, P2) << std::endl;

	return 0;
}
