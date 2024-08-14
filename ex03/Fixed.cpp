#include "Fixed.hpp"

int const Fixed::bits(8);

Fixed::Fixed(void) : fix(0)
{
}

Fixed::Fixed(const int n) : fix(n << bits)
{
}

Fixed::Fixed(const float n) : fix(std::round(n * (1 << bits)))
{
}

// A copy constructor :

Fixed::Fixed(Fixed const &src) : fix(src.fix)
{
}

// A copy assignment operator overload :

Fixed &Fixed::operator=(const Fixed &rhs)
{
    if (this != &rhs)
    {
        this->fix = rhs.getRawBits();
    }
    return *this;
}

// surcharge de l operateur d insertion
std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return o;
}
// A destructor :

Fixed::~Fixed(void)
{
}

// A member function that returns the raw value of the fixed - point value :

int Fixed::getRawBits(void) const
{
    return (this->fix);
}

// A member function that sets the raw value of the fixed - point number

void Fixed::setRawBits(int const raw)
{
    this->fix = raw;
}

// ignore la partie fractionnaire
int Fixed::toInt(void) const
{
    return (fix >> bits);
}

// nb a virgule flottante

float Fixed::toFloat(void) const
{
    return static_cast<float>(fix) / (1 << bits);
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->fix > rhs.fix);
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->fix < rhs.fix);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->fix >= rhs.fix);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->fix <= rhs.fix);
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->fix == rhs.fix);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->fix != rhs.fix);
}

/*
    -> Conversion from fixed point rpz to floating point used to
    -> Simplify the addition + add precision
    -> Creates a new Fixed object from the result of the addition. 
        Use the constructor that takes a float as a parameter
        to create the new Fixed object.
*/

Fixed Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator /(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator ++()
{
    this->fix++;
    return *this;
}

Fixed Fixed::operator ++(int n)
{
    Fixed temp(*this);
    this->fix++;
    return temp;
}

Fixed& Fixed::operator --()
{
    this->fix--;
    return *this;
}

Fixed Fixed::operator --(int n)
{
    Fixed temp(*this);
    this->fix--;
    return temp;
}

Fixed& Fixed::min(Fixed &one, Fixed &two)
{
    if (one <= two)
        return one;
    else
        return two;
}

const Fixed& Fixed::min(const Fixed &one, const Fixed &two)
{
    if (one <= two)
        return one;
    else
        return two;
}

Fixed& Fixed::max(Fixed &one, Fixed &two)
{
    if (one >= two)
        return one;
    else
        return two;
}

const Fixed& Fixed::max(const Fixed &one, const Fixed &two)
{
    if (one >= two)
        return one;
    else
        return two;
}