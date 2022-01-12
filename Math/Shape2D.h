#pragma once
#include "Fraction.h"
#include "Coordinate2D.h"

class Circle;
//class Triangle;
class Rectangle;

class Shape2D
{
protected:
    Coordinate2D pos_;

public:
    Shape2D(const Coordinate2D& new_pos);

    virtual bool operator==(const Shape2D& other) const = 0;
    virtual bool operator!=(const Shape2D& other) const = 0;

    virtual bool equals(const Circle& other) const;
    virtual bool equals(const Rectangle& other) const;
    /*virtual bool equals(const Triangle& other);
    */

public:
    virtual Fraction Perimeter() const = 0;
    virtual Fraction Area() const = 0;
    virtual bool IsInside(const Coordinate2D& point) const = 0;
    //virtual bool Overlap(const Shape& Shape2D) const = 0;
};

