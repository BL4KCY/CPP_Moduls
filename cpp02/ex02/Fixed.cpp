#include "Fixed.hpp"

// constructor
Fixed::Fixed(): fixedPoint(0){}

// copy constructor
Fixed::Fixed( const Fixed &f )
{
	this->fixedPoint = f.fixedPoint;
}

// destructor
Fixed::~Fixed(){}

// assignment operator
Fixed& Fixed::operator=( const Fixed &copy )
{
	fixedPoint = copy.fixedPoint;
	return (*this);
}

// raw bits getter
int		Fixed::getRawBits( void ) const
{
	return (fixedPoint);
}

// raw bits setter
void	Fixed::setRawBits( int const raw )
{
	this->fixedPoint = raw;
}

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
	return ((float)fixedPoint / (1 << fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (roundf(fixedPoint >> fractionalBits));
}

std::ostream&	operator<<(std::ostream& cout, const Fixed& fixedObject)
{
	return (cout << fixedObject.toFloat());
}

// Ex-02

// Comparison operators:
bool			Fixed::operator>( const Fixed &toCmp ) const
{
	return (this->fixedPoint > toCmp.fixedPoint);
}
bool			Fixed::operator>=( const Fixed &toCmp ) const
{
	return (this->fixedPoint >= toCmp.fixedPoint);
}
bool			Fixed::operator<( const Fixed &toCmp ) const
{
	return (this->fixedPoint < toCmp.fixedPoint);
}
bool			Fixed::operator<=( const Fixed &toCmp ) const
{
	return (this->fixedPoint <= toCmp.fixedPoint);
}
bool			Fixed::operator==( const Fixed &toCmp ) const
{
	return (this->fixedPoint == toCmp.fixedPoint);
}
bool			Fixed::operator!=( const Fixed &toCmp ) const
{
	return (this->fixedPoint != toCmp.fixedPoint);
}

// Arithmetic operators:

Fixed			Fixed::operator+( const Fixed &toAdd ) const
{
	return Fixed(this->toFloat() + toAdd.toFloat());
}

Fixed			Fixed::operator-( const Fixed &toSub ) const
{
	return Fixed(this->toFloat() - toSub.toFloat());
}

Fixed			Fixed::operator*( const Fixed &toMul ) const
{
	return Fixed(this->toFloat() * toMul.toFloat());
}

Fixed			Fixed::operator/( const Fixed &divby ) const
{
	return Fixed(this->toFloat() / divby.toFloat());
}

//  increment/decrement
Fixed&			Fixed::operator++()
{
	this->fixedPoint++;
	return (*this);
}
Fixed			Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->fixedPoint++;
	return (tmp);
}
Fixed&			Fixed::operator--()
{
	this->fixedPoint--;
	return (*this);
}
Fixed			Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->fixedPoint--;
	return (tmp);
}

// min/max member function

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}
const	Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (((Fixed)a > b) ? a : b);
}
const	Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (((Fixed)a < b) ? a : b);
}
