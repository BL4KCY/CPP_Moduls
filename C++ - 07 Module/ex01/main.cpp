#include "iter.hpp"

void print_int( int const & x ) { std::cout << x << std::endl;}
void print_string( std::string const & x ) { std::cout << x << std::endl;}
void print_double( double const & x ) { std::cout << x << std::endl;}
void print_char( char const & x ) { std::cout << x << std::endl;}


int main( void ) {
	int a[] = {1, 2, 3, 4, 5};
	std::string b[] = {"one", "two", "three", "four", "five"};
	double c[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char d[] = {'a', 'b', 'c', 'd', 'e'};
	cout << "int array:" << endl;
	iter(a, 5, print_int);
	cout << "string array:" << endl;
	iter(b, 5, print_string);
	cout << "double array:" << endl;
	iter(c, 5, print_double);
	cout << "char array:" << endl;
	iter(d, 5, print_char);

	return 0;
}
