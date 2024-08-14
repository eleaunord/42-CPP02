#include "Point.hpp"
#include "Fixed.hpp"

static Fixed computeW1(Point const a, Point const b, Point const c, Point const point, Fixed const &dX, Fixed const &dY, Fixed const &eX, Fixed const &eY)
{
	if (dX * eY - dY * eX == Fixed(0))
	{
		return (eX * (a.getY() - point.getY()) + eY * (point.getX() - a.getX())) / Fixed(0.002f);
	}
	else
	{
		return (eX * (a.getY() - point.getY()) + eY * (point.getX() - a.getX())) / (dX * eY - dY * eX);
	}
}

static Fixed computeW2(Point const a, Point const point, Fixed const &w1, Fixed const &dY, Fixed const &eY)
{
	if (eY == Fixed(0))
	{
		return (point.getY() - a.getY() - w1 * dY) / Fixed(0.002f);
	}
	else
	{
		return (point.getY() - a.getY() - w1 * dY) / eY;
	}
}

static bool isInsideTriangle(Fixed const &w1, Fixed const &w2, Fixed const &uno)
{
	return (w1 > Fixed(0) && w2 > Fixed(0) && (w1 + w2) < uno);
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point const d(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
	Point const e(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() - a.getY().toFloat());

	Fixed const w1 = computeW1(a, b, c, point, d.getX(), d.getY(), e.getX(), e.getY());
	Fixed const w2 = computeW2(a, point, w1, d.getY(), e.getY());
	Fixed const uno(1.0f);

	return isInsideTriangle(w1, w2, uno);
}
