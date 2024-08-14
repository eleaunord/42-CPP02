#include "Fixed.hpp"

int const Fixed::bits(8);

// A default constructor that initializes the fixed-point number value to 0 :

Fixed::Fixed(void) : fix(0)
{
    std::cout << "Default constructor called"
              << std::endl;
}

Fixed::Fixed(const int n) : fix(n << bits)
{
    std::cout << "Int constructor called"
              << std::endl;
}

Fixed::Fixed(const float n) : fix(std::round(n * (1 << bits)))
{
    std::cout << "Float constructor called"
              << std::endl;
}

// A copy constructor :

Fixed::Fixed(Fixed const &src) : fix(src.fix)
{
    std::cout << "Copy constructor called"
              << std::endl;
}

// A copy assignment operator overload :

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called"
              << std::endl;
    if (this != &rhs)
    {
        this->fix = rhs.getRawBits();
    }
    // return a ref to the current object so we can do a chaining of assignments (a = b = c)
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
    std::cout << "Destructor called"
              << std::endl;
    return;
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

/*

NOTES

COPY CONSTRUCTOR

fix(src.fix) => member wise copy of the fix bar from the src

object to the current object being constructer

init new fix member of the new Fixed object with the value of fix from source object

fix construit a partir de la valeur src.fix fix

COPY ASSIGNEMENT OPERATOR

(rhs = right hand side object = the object from which values are being copied)

*/