#pragma once

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed
{
private:
	int					fixedPoint;
	static const int	fractionalBits = 8;
public:
	Fixed();
	Fixed(int intValue);
	Fixed(float floatValue);
	Fixed( const Fixed &f );
	~Fixed();

	Fixed&			operator=( const Fixed &copy );
	//  Comparison operators:
	bool			operator>( const Fixed &tocmp );
	bool			operator>=( const Fixed &tocmp );
	bool			operator<( const Fixed &tocmp );
	bool			operator<=( const Fixed &tocmp );
	bool			operator==( const Fixed &tocmp );
	bool			operator!=( const Fixed &tocmp );
	// Arithmetic operators:
	Fixed&			operator+( const Fixed &toadd );
	Fixed&			operator-( const Fixed &tosub );
	Fixed&			operator*( const Fixed &tomul );
	Fixed&			operator/( const Fixed &todiv );
	//  increment/decrement
	Fixed&			operator++();
	Fixed			operator++(int);
	Fixed&			operator--();
	Fixed			operator--(int);

	int				getRawBits( void ) const;
	void			setRawBits( int const raw );
	float			toFloat( void ) const;
	int				toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& cout, const Fixed& fixedObject);
