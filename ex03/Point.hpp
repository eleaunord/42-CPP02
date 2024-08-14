#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <math.h>
#include "Fixed.hpp"
#include <cmath>
#include <string>

class Point
{

private:
	const Fixed _x;
	const Fixed _y;

public:
	Point();
	Point(const float fx, const float fy);
	Point(const Point &src);
	~Point();

	Point &operator=(const Point &rhs);

	Fixed getX(void) const;
	Fixed getY(void) const;

};

std::ostream &operator<<(std::ostream &o, Point const &i);

#endif