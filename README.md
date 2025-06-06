# C++ Module 02 – Canonical Classes and BSP

## Overview

This project was part of the C++ modules focused on deepening understanding of **Object-Oriented Programming** principles, with special attention to **ad-hoc polymorphism**, **operator overloading**, and implementing classes in the **Orthodox Canonical Form**.

Throughout the exercises, I implemented a class to represent **fixed-point numbers**, learned how to make classes well-behaved in terms of memory management and copying, and finally used that class to solve a geometric problem using **Binary Space Partitioning (BSP)**.

---

## 🚀 What I Learned

### Orthodox Canonical Form

A **canonical class** adheres to specific conventions that ensure safe object behavior across construction, copying, assignment, and destruction. These include:

* **Default constructor**
* **Copy constructor**
* **Copy assignment operator**
* **Destructor**

This ensures robust memory handling and predictable behavior when objects are passed by value or copied.

### Fixed-Point Numbers

I learned how fixed-point numbers can be used as an alternative to floating-point numbers when performance and precision need to be balanced. Implementing this involved:

* Storing values as integers internally.
* Defining constructors to accept `int` and `float`.
* Converting between fixed-point and float/int using bit shifts.
* Overloading the `<<` operator for clean output.

### Operator Overloading

The module also required overloading:

* Arithmetic operators: `+`, `-`, `*`, `/`
* Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
* Increment and decrement operators (prefix and postfix)

This was my first real practice with **polymorphism in C++**, and it helped me better understand how operators can be tailored for custom data types.

### BSP with Barycentric Coordinates

In the final part, I created a `Point` class and used it to implement a `bsp()` function to check if a point lies inside a triangle using **barycentric coordinates**. This involved:

* Understanding vector math and cross products.
* Managing const-correctness in classes.
* Handling geometric edge cases like collinearity.

---

## 😓 Difficulties Encountered

* **Understanding fixed-point math**: Initially confusing, especially the bit manipulation needed to convert between float and fixed-point.
* **Operator overloading complexity**: Some operators, especially increment/decrement, had subtle differences between prefix and postfix versions.
* **Memory management**: Making sure I wasn’t causing memory leaks or shallow copies while sticking to the Canonical Form.
* **BSP math**: Implementing barycentric coordinates and understanding vector cross products was mathematically challenging but rewarding.

---

## 🧠 Concepts Recap (Notes)

### Canonical Classes

A class that respects the four canonical methods to ensure predictable object behavior.

### Floating Point Constructor

```cpp
MyClass(double val) : value(val) {}
```

### Barycentric Coordinates for BSP

Check if a point is in a triangle using weights `w1`, `w2`, and `w3 = 1 - w1 - w2`. If `w1`, `w2`, and `w3` are between 0 and 1, the point is inside.

Cross product-based computation:

```cpp
return (eX * (a.getY() - point.getY()) + eY * (point.getX() - a.getX())) / (dX * eY - dY * eX);
```

---

## 🎯 Final Thoughts

This module made me more comfortable with class design in C++ and taught me to think like a systems programmer. I now better appreciate why C++ emphasizes memory control and object behavior—and how math and code come together in real-world scenarios like geometry and graphics.

---

Let me know if you'd like this formatted for GitHub or want me to generate a visual summary or diagram for the BSP logic!
