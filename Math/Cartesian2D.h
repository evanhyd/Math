#pragma once
#include "Fraction.h"

namespace geometry
{
    class Cartesian2D
    {
        Fraction x_;
        Fraction y_;

    public:

        Cartesian2D(const Fraction& new_x, const Fraction& new_y);

        bool operator==(const Cartesian2D& other) const;
        bool operator!=(const Cartesian2D& other) const;

        void operator+=(const Cartesian2D& addend);
        void operator-=(const Cartesian2D& subtrahend);
        void operator*=(const Fraction& scalar);
        void operator/=(const Fraction& divisor);

        Cartesian2D operator+(const Cartesian2D& addend) const;
        Cartesian2D operator-(const Cartesian2D& subtrahend) const;
        Cartesian2D operator*(const Fraction& scalar) const;
        Cartesian2D operator/(const Fraction& divisor) const;

        const Fraction& GetX() const;
        const Fraction& GetY() const;
        void SetX(const Fraction& new_x);
        void SetY(const Fraction& new_y);

        Fraction Magnitude() const;
        Cartesian2D UnitVector() const;
        bool IsZero() const;
        void SetZero();
    };
}


