#include "Fixed.hpp"


Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed( const Fixed &f )
{
	std::cout << "Copy constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

}

Fixed& Fixed::operator=( const Fixed &copy )
{
	std::cout << "Copy assignment operator called" << std::endl;

}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	this->fixedPoint = raw;
}
