#pragma once
#include "Shape2D.h"

class Circle final : public Shape2D
{
    Fraction radius_;

public:
    Circle(const Coordinate2D& new_pos, const Fraction& new_radius);

    virtual bool operator==(const Shape2D& other) const override;
    virtual bool operator!=(const Shape2D& other) const override;
    virtual bool equals(const Circle& other) const override;

public:
    virtual Fraction Perimeter() const override;
    virtual Fraction Area() const override;
    virtual bool IsInside(const Coordinate2D& point) const override;
    //virtual bool Overlap(const Fraction& Shape2D) const override;
};

