#pragma once
#include "Shape2D.h"

namespace geometry
{
    class Rectangle : public Shape2D
    {
        double width_;
        double length_;

    public:
        explicit Rectangle(const Cartesian2D& new_pos, double new_width, double new_length);

        virtual bool operator==(const Shape2D& other) const override;
        virtual bool operator!=(const Shape2D& other) const override;
        virtual bool equals(const Rectangle& other) const override;

    public:
        virtual double Perimeter() const override;
        virtual double Area() const override;
        virtual bool IsPointInside(const Cartesian2D& point) const override;
        //virtual bool Overlap(const Fraction& Shape2D) const override;
    };
}

