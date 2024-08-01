#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

// constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

// copy constructor
Fixed::Fixed( const Fixed &f )
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPoint = f.fixedPoint;
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// assignment operator
Fixed& Fixed::operator=( const Fixed &copy )
{
	std::cout << "Copy assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

// raw bits getter
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}

// raw bits setter
void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}
