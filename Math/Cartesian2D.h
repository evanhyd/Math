#pragma once

namespace geometry
{
    class Cartesian2D
    {
        double x_;
        double y_;

    public:

        explicit Cartesian2D(double new_x, double new_y);

        Cartesian2D& operator+=(const Cartesian2D& addend);
        Cartesian2D& operator-=(const Cartesian2D& subtrahend);
        Cartesian2D& operator*=(double scalar);
        Cartesian2D& operator/=(double divisor);


        double X() const;
        double& X();
        double Y() const;
        double& Y();

        double Magnitude() const;
        Cartesian2D UnitVector() const;
        bool IsZero() const;
        void SetZero();


        friend Cartesian2D operator+(Cartesian2D lhs, const Cartesian2D& addend);
        friend Cartesian2D operator-(Cartesian2D lhs, const Cartesian2D& subtrahend);
        friend Cartesian2D operator*(Cartesian2D lhs, double scalar);
        friend Cartesian2D operator/(Cartesian2D lhs, double divisor);
        friend bool operator==(const Cartesian2D& lhs, const Cartesian2D& rhs);
        friend bool operator!=(const Cartesian2D& lhs, const Cartesian2D& rhs);
    };

    Cartesian2D operator+(Cartesian2D lhs, const Cartesian2D& addend);
    Cartesian2D operator-(Cartesian2D lhs, const Cartesian2D& subtrahend);
    Cartesian2D operator*(Cartesian2D lhs, double scalar);
    Cartesian2D operator/(Cartesian2D lhs, double divisor);
    bool operator==(const Cartesian2D& lhs, const Cartesian2D& rhs);
    bool operator!=(const Cartesian2D& lhs, const Cartesian2D& rhs);
}


