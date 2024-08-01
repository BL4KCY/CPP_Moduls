#pragma once

#include <iostream>
#include <iostream>

class Fixed
{
private:
	int					fixedPoint;
	static const int	fractionalBits = 8;
public:
	Fixed();
	Fixed( const Fixed &f );
	~Fixed();
	Fixed&	operator=( const Fixed &copy );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
