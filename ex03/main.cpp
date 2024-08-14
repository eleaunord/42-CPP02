#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{

    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point inside(2.5f, 2.5f);  // Inside the triangle
    Point onEdge(2.5f, 0.0f);  // On the edge of the triangle
    Point outside(6.0f, 3.0f); // Outside the triangle

    // Test cases
    std::cout << "Testing point (2.5, 2.5): " << (bsp(a, b, c, inside) ? "Inside" : "Not inside") << std::endl;
    std::cout << "Testing point (2.5, 0.0): " << (bsp(a, b, c, onEdge) ? "Inside" : "Not inside") << std::endl;
    std::cout << "Testing point (6.0, 3.0): " << (bsp(a, b, c, outside) ? "Inside" : "Not inside") << std::endl;

    return 0;
}
