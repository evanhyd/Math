#pragma once
#include "Fraction.h"
#include "Cartesian2D.h"


namespace geometry
{
    class Circle;
    class Rectangle;

    class Shape2D
    {
    protected:
        Cartesian2D pos_;

    public:
        Shape2D(const Cartesian2D& new_pos);

        virtual bool operator==(const Shape2D& other) const = 0;
        virtual bool operator!=(const Shape2D& other) const = 0;

        virtual bool equals(const Circle& other) const;
        virtual bool equals(const Rectangle& other) const;
        /*virtual bool equals(const Triangle& other);
        */

    public:
        virtual Fraction Perimeter() const = 0;
        virtual Fraction Area() const = 0;
        virtual bool IsPointInside(const Cartesian2D& point) const = 0;
        //virtual bool Overlap(const Shape& Shape2D) const = 0;
    };
}
