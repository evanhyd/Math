#pragma once

namespace geometry
{
    class Polar2D
    {
        double magnitude_;
        double angle_; //(-PI, PI]

    public:

        explicit Polar2D(double new_magnitude, double new_angle);

        bool operator==(const Polar2D& other) const;
        bool operator!=(const Polar2D& other) const;

        Polar2D& operator+=(const Polar2D& addend);
        Polar2D& operator-=(const Polar2D& subtrahend);
        Polar2D& operator*=(double scalar);
        Polar2D& operator/=(double divisor);

        Polar2D operator+ (const Polar2D& addend) const;
        Polar2D operator- (const Polar2D& subtrahend) const;
        Polar2D operator* (double scalar) const;
        Polar2D operator/(double divisor) const;


        double GetMagnitude() const;
        double GetAngle() const;
        void SetMagnitude(double new_magnitude);
        void SetAngle(double new_angle);

        Polar2D UnitPolar() const;
        bool IsZero() const;
    };
}


