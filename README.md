## Canonical classes
canonical class = a class that adheres to a set of conventions that make it well-behaved in terms of object creation, copying, assignment, and destruction. 
1 - Default Constructor: A constructor that takes no arguments and initializes the object.
2 - Copy Constructor: A constructor that creates a new object as a copy of an existing object. This is used when an object is passed by value, or when a copy of an object is made.
3 - Copy Assignment Operator: An operator that assigns the contents of one object to another existing object.
4 - Destructor: A method that cleans up any resources (e.g., memory, file handles) when an object is destroyed.

## Constructor via Floating Point
To construct an instance from a floating-point number, you need to define a constructor that accepts a floating-point argument (such as float or double). 
Example :

class MyClass {
private:
    double value;
    
public:
    // Constructor that takes a floating-point number
    MyClass(double val) : value(val) {
        std::cout << "Constructor called with value: " << value << std::endl;
    }

  // Method to get the stored value
    double getValue() const {
        return value;
    }
};

## Binary space partitioning using the barycentric coordinates method

### Barycentric coordinates
3 weights (position of a point depending on the vertice) of a triangle : w1, w2, w3 (= 1 - w1 - w2) for a point P
if w1 || w2 < 1 && w1 and w2 positive then the point is inside the triangle

Vectors= sides of the triangles
Point const d(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
Point const e(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() - a.getY().toFloat());

d : vector from point a to point b
e : vector from point a to point c 

Cross product of vectors
return (eX * (a.getY() - point.getY()) + eY * (point.getX() - a.getX())) / (dX * eY - dY * eX);



