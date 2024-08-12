#include "Point.hpp"



Point::Point(): x(0), y(0) {}

Point::Point( const Fixed _x, const Fixed _y ): x(_x), y(_y) {}

Point::Point( const Point& p ): x(p.x), y(p.y) {}

Point&	Point::operator=( const Point& copy )
{
	std::cout << "You can't copy constant attributes!!" << std::endl;
	(void)copy;
	return (*this);
}

Point::~Point() {}

const Fixed&	Point::getX(void) const
{
	return (this->x);
}

const Fixed&	Point::getY(void) const
{
	return (this->y);
}
