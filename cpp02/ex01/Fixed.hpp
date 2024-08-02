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
	int				getRawBits( void ) const;
	void			setRawBits( int const raw );
	float			toFloat( void ) const;
	int				toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& cout, const Fixed& fixedObject);
