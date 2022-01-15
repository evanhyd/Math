#pragma once
#include "Fraction.h"

namespace geometry
{
    class Polar2D
    {
        Fraction magnitude_;
        Fraction angle_; //(-PI, PI]

    public:

        Polar2D(const Fraction& new_magnitude, const Fraction& new_angle);

        bool operator==(const Polar2D& other) const;
        bool operator!=(const Polar2D& other) const;

        void operator+=(const Polar2D& addend);
        void operator-=(const Polar2D& subtrahend);
        void operator*=(const Fraction& scalar);
        void operator/=(const Fraction& divisor);

        Polar2D operator + (const Polar2D& addend) const;
        Polar2D operator - (const Polar2D& subtrahend) const;
        Polar2D operator* (const Fraction& scalar) const;
        Polar2D operator/(const Fraction& divisor) const;


        const Fraction& GetMagnitude() const;
        const Fraction& GetAngle() const;
        void SetMagnitude(const Fraction& new_magnitude);
        void SetAngle(const Fraction& new_angle);

        Polar2D UnitPolar() const;
        bool IsZero() const;
    };
}


