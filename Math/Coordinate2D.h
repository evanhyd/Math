#pragma once
#include "Fraction.h"

class Coordinate2D
{
public:

    Fraction x_;
    Fraction y_;

    Coordinate2D(Fraction new_x, Fraction new_y);

    bool operator==(const Coordinate2D& other) const;
    bool operator!=(const Coordinate2D& other) const;

    void operator+=(const Coordinate2D& addend);
    void operator-=(const Coordinate2D& subtrahend);
    void operator*=(const Fraction& scalar);
    void operator/=(const Fraction& divisor);

    Coordinate2D operator+(const Coordinate2D& addend) const;
    Coordinate2D operator-(const Coordinate2D& subtrahend) const;
    Coordinate2D operator*(const Fraction& scalar) const;
    Coordinate2D operator/(const Fraction& divisor) const;

    Fraction Magnitude() const;
    Coordinate2D UnitVector() const;
    bool IsZero() const;
    void SetZero();
};

