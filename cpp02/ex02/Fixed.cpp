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
	return ((float)fixedPoint / ((float)(1 << fractionalBits)));
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
bool			Fixed::operator>( const Fixed &toCmp )
{
	return (this->fixedPoint > toCmp.fixedPoint);
}
bool			Fixed::operator>=( const Fixed &toCmp )
{
	return (this->fixedPoint >= toCmp.fixedPoint);
}
bool			Fixed::operator<( const Fixed &toCmp )
{
	return (this->fixedPoint < toCmp.fixedPoint);
}
bool			Fixed::operator<=( const Fixed &toCmp )
{
	return (this->fixedPoint <= toCmp.fixedPoint);
}
bool			Fixed::operator==( const Fixed &toCmp )
{
	return (this->fixedPoint == toCmp.fixedPoint);
}
bool			Fixed::operator!=( const Fixed &toCmp )
{
	return (this->fixedPoint != toCmp.fixedPoint);
}

// Arithmetic operators:

Fixed&			Fixed::operator+( const Fixed &toAdd )
{
	this->fixedPoint += toAdd.fixedPoint;
	return (*this);
}

Fixed&			Fixed::operator-( const Fixed &toSub )
{
	this->fixedPoint -= toSub.fixedPoint;
	return (*this);
}

Fixed&			Fixed::operator*( const Fixed &toMul )
{
	this->fixedPoint = Fixed(this->toFloat() * toMul.toFloat()).fixedPoint;
	return (*this);
}

Fixed&			Fixed::operator/( const Fixed &divby )
{
	this->fixedPoint = Fixed(this->toFloat() / divby.toFloat()).fixedPoint;
	return (*this);
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

