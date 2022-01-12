#pragma once
#include "Shape2D.h"
class Rectangle : public Shape2D
{
    Fraction width_;
    Fraction length_;

public:
    Rectangle(const Coordinate2D& new_pos, const Fraction& new_width, const Fraction& new_length);

    virtual bool operator==(const Shape2D& other) const override;
    virtual bool operator!=(const Shape2D& other) const override;
    virtual bool equals(const Rectangle& other) const override;

public:
    virtual Fraction Perimeter() const override;
    virtual Fraction Area() const override;
    virtual bool IsInside(const Coordinate2D& point) const override;
    //virtual bool Overlap(const Fraction& Shape2D) const override;
};

