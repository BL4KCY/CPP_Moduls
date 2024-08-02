#include "Fixed.hpp"

// constructor
Fixed::Fixed(): fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
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
	fixedPoint = copy.fixedPoint;
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

// Ex01

Fixed::Fixed(int intValue)
{
	fixedPoint = intValue << fractionalBits;
}
Fixed::Fixed(float floatValue)
{
	fixedPoint = roundf(floatValue * (1 << fractionalBits));
}

float	Fixed::toFloat( void ) const
{
	return ((float)fixedPoint / (float)(1 << fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (fixedPoint >> fractionalBits);
}

std::ostream&	operator<<(std::ostream& cout, const Fixed& fixedObject)
{
	return (cout << fixedObject.toFloat());
}
