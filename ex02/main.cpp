#include <iostream>
#include "Fixed.hpp"

int main(void)
{

    std::cout << "Main from the subject:" << std::endl;

    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << std::endl;

    std::cout << "My main:" << std::endl;

    Fixed myA;
    Fixed const myB(Fixed(5.05f) * Fixed(2));
    Fixed const c(42.42f);
    Fixed const d(10);

    std::cout << "Initial values:" << std::endl;
    std::cout << "a: " << myA << std::endl;
    std::cout << "b: " << myB << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    // Arithmetic operators
    Fixed sum = myB + c;
    Fixed difference = c - myB;
    Fixed product = c * d;
    Fixed division = c / d;

    std::cout << "\nArithmetic operations:" << std::endl;
    std::cout << "b + c = " << sum << std::endl;
    std::cout << "c - b = " << difference << std::endl;
    std::cout << "c * d = " << product << std::endl;
    std::cout << "c / d = " << division << std::endl;

    // Comparison operators
    std::cout << "\nComparison operations:" << std::endl;
    std::cout << "c > b: " << (c > myB) << std::endl;
    std::cout << "c < b: " << (c < myB) << std::endl;
    std::cout << "c >= b: " << (c >= myB) << std::endl;
    std::cout << "c <= b: " << (c <= myB) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;

    // Increment/Decrement operators
    std::cout << "\nIncrement and Decrement operations:" << std::endl;
    std::cout << "a before increment: " << myA << std::endl;
    std::cout << "++a (pre-increment): " << ++myA << std::endl;
    std::cout << "a after pre-increment: " << myA << std::endl;
    std::cout << "a++ (post-increment): " << myA++ << std::endl;
    std::cout << "a after post-increment: " << myA << std::endl;
    std::cout << "--a (pre-decrement): " << --myA << std::endl;
    std::cout << "a after pre-decrement: " << myA << std::endl;
    std::cout << "a-- (post-decrement): " << myA-- << std::endl;
    std::cout << "a after post-decrement: " << myA << std::endl;

    // Static min/max functions
    std::cout << "\nStatic min/max functions:" << std::endl;
    std::cout << "Min of b and c: " << Fixed::min(myB, c) << std::endl;
    std::cout << "Max of b and c: " << Fixed::max(myB, c) << std::endl;
    std::cout << "Max of a and b: " << Fixed::max(myA, myB) << std::endl;

    // Assignment operator
    std::cout << "\nAssignment operation:" << std::endl;
    Fixed e;
    e = c; // Test assignment operator
    std::cout << "e after assignment (e = c): " << e << std::endl;

    return 0;
}