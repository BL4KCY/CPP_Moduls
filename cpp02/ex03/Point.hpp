
#pragma once

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed y;
public:
	Point();
	Point(const Fixed _x, const Fixed _y);
	Point(const Point& p);
	Point&	operator=(const Point& copy);
	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;
	~Point();
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
