#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{

private:
    int fix;
    static const int bits;

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &src);
    ~Fixed();

    Fixed& operator=(const Fixed &rhs);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    // comparison operators overloading
    bool operator >(const Fixed &rhs) const;
    bool operator <(const Fixed &rhs) const;
    bool operator >=(const Fixed &rhs) const;
    bool operator <=(const Fixed &rhs) const;
    bool operator ==(const Fixed &rhs) const;
    bool operator !=(const Fixed &rhs) const;

    // arithmetic operators overloading
    Fixed operator +(const Fixed &rhs) const;
    Fixed operator -(const Fixed &rhs) const;
    Fixed operator *(const Fixed &rhs) const;
    Fixed operator /(const Fixed &rhs) const;

    // increment/decrement operators overloading
    Fixed& operator ++(); // pre-increment
    Fixed operator ++(int n); // post-increment
    Fixed& operator --(); // pre-decrement
    Fixed operator --(int n); // post-decrement

    // static memb functions
    static Fixed& min(Fixed &one, Fixed &two);
    static const Fixed& min(const Fixed &one, const Fixed &two);
    static Fixed& max(Fixed &one, Fixed &two);
    static const Fixed& max(const Fixed &one, const Fixed &two);
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif