#pragma once

namespace geometry
{
    class Cartesian2D
    {
        double x_;
        double y_;

    public:

        explicit Cartesian2D(double new_x, double new_y);

        bool operator==(const Cartesian2D& other) const;
        bool operator!=(const Cartesian2D& other) const;

        void operator+=(const Cartesian2D& addend);
        void operator-=(const Cartesian2D& subtrahend);
        void operator*=(double scalar);
        void operator/=(double divisor);

        Cartesian2D operator+(const Cartesian2D& addend) const;
        Cartesian2D operator-(const Cartesian2D& subtrahend) const;
        Cartesian2D operator*(double scalar) const;
        Cartesian2D operator/(double divisor) const;

        double GetX() const;
        double GetY() const;
        void SetX(double new_x);
        void SetY(double new_y);

        double Magnitude() const;
        Cartesian2D UnitVector() const;
        bool IsZero() const;
        void SetZero();
    };
}


