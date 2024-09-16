#include "Fixed.hpp"

#include <iostream>

int main(void)
{
    Fixed a;
    Fixed const b(10);     
    Fixed const c(42.42f);
    Fixed const d(b); // copy constructor
    a = Fixed(1234.4321f); // floating-point number to 'a'

    //fixed-point numbers as floating-point values using toFloat()
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    //  toFloat() function (added to the main in the subject)
    std::cout << "a as float: " << a.toFloat() << std::endl;
    std::cout << "b as float: " << b.toFloat() << std::endl;
    std::cout << "c as float: " << c.toFloat() << std::endl;
    std::cout << "d as float: " << d.toFloat() << std::endl;

    // toInt() function
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
