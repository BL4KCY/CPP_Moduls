#include "Point.hpp"

// Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
float	area(const Point& a, const Point& b, const Point& c)
{
	float	A = (
		(
			a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
			+
			b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
			+
			c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())
		) / 2
	);

	return ((0 > A) ? (A) : (A));
}
bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float trArea = area(a, b, c);

	float A1 = area(a, b, point);
	float A2 = area(a, point, c);
	float A3 = area(point, b, c);

	return ((A1 + A2 + A3 == trArea));
}

