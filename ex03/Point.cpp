
#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : _x(0), _y(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float fx, const float fy) : _x(fx), _y(fy)
{
	//std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
	//std::cout << "Copy constructor called" << std::endl;
}
std::ostream &operator<<(std::ostream &os, Point const &other)
{
	os << "(" << other.getX() << "," << other.getY() << ")";
	return os;
}

// const_cast to bypass const qualifications
Point &Point::operator=(const Point &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		const_cast<Fixed &>(this->_x) = other._x;
		const_cast<Fixed &>(this->_y) = other._y;
	}
	return *this;
}
Point::~Point(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}