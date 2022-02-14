#pragma once

namespace geometry
{
    class Polar2D
    {
        double magnitude_;
        double angle_; //(-PI, PI]

    public:

        explicit Polar2D(double new_magnitude, double new_angle);

        Polar2D& operator+=(const Polar2D& addend);
        Polar2D& operator-=(const Polar2D& subtrahend);
        Polar2D& operator*=(double scalar);
        Polar2D& operator/=(double divisor);

        double& Magnitude();
        double Magnitude() const;
        double& Angle();
        double Angle() const;

        Polar2D UnitPolar() const;
        bool IsZero() const;


        friend Polar2D operator+ (Polar2D lhs, const Polar2D& addend);
        friend Polar2D operator- (Polar2D lhs, const Polar2D& subtrahend);
        friend Polar2D operator* (Polar2D lhs, double scalar);
        friend Polar2D operator/(Polar2D lhs, double divisor);
        friend bool operator==(const Polar2D& lhs, const Polar2D& rhs);
        friend bool operator!=(const Polar2D& lhs, const Polar2D& rhs);
    };

    Polar2D operator+ (Polar2D lhs, const Polar2D& addend);
    Polar2D operator- (Polar2D lhs, const Polar2D& subtrahend);
    Polar2D operator* (Polar2D lhs, double scalar);
    Polar2D operator/(Polar2D lhs, double divisor);
    bool operator==(const Polar2D& lhs, const Polar2D& rhs);
    bool operator!=(const Polar2D& lhs, const Polar2D& rhs);
}


