#pragma once
#include "Shape2D.h"

namespace geometry
{
    class Circle final : public Shape2D
    {
        Fraction radius_;

    public:
        Circle(const Cartesian2D& new_pos, const Fraction& new_radius);

        virtual bool operator==(const Shape2D& other) const override;
        virtual bool operator!=(const Shape2D& other) const override;
        virtual bool equals(const Circle& other) const override;

    public:
        virtual Fraction Perimeter() const override;
        virtual Fraction Area() const override;
        virtual bool IsPointInside(const Cartesian2D& point) const override;
        //virtual bool Overlap(const Fraction& Shape2D) const override;
    };
}
