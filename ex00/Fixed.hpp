#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{

private:
    int fix;
    static const int bits;

public:
    Fixed();
    Fixed(const Fixed &src);
    ~Fixed();

    Fixed& operator=(const Fixed &rhs);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

// std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif