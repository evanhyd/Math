#include "Polar2D.h"
#include <cmath>

using namespace geometry;

Polar2D::Polar2D(double new_magnitude, double new_angle) : magnitude_(new_magnitude), angle_(new_angle)
{
    //empty
}

     
Polar2D& Polar2D::operator+=(const Polar2D& addend)
{
    double x = magnitude_ * cos(angle_) + addend.magnitude_ * cos(addend.angle_);
    double y = magnitude_ * sin(angle_) + addend.magnitude_ * sin(addend.angle_);

    magnitude_ = hypot(x, y);
    angle_ = atan2(y, x);

    return *this;
}
Polar2D& Polar2D::operator-=(const Polar2D& subtrahend)
{
    double x = magnitude_ * cos(angle_) - subtrahend.magnitude_ * cos(subtrahend.angle_);
    double y = magnitude_ * sin(angle_) - subtrahend.magnitude_ * sin(subtrahend.angle_);

    magnitude_ = hypot(x, y);
    angle_ = atan2(y, x);

    return *this;
}
Polar2D& Polar2D::operator*=(double scalar)
{
    magnitude_ *= scalar;
    return *this;
}
Polar2D& Polar2D::operator/=(double divisor)
{
    magnitude_ /= divisor;
    return *this;
}


double& Polar2D::Magnitude()
{
    return magnitude_;
}
double Polar2D::Magnitude() const
{
    return magnitude_;
}
double& Polar2D::Angle()
{
    return angle_;
}
double Polar2D::Angle() const
{
    return angle_;
}


Polar2D Polar2D::UnitPolar() const
{
    return Polar2D(1.0, angle_);
}
bool Polar2D::IsZero() const
{
    return magnitude_ == 0.0;
}






Polar2D geometry::operator+ (Polar2D lhs, const Polar2D& addend)
{
    lhs += addend;
    return lhs;
}

Polar2D geometry::operator- (Polar2D lhs, const Polar2D& subtrahend)
{
    lhs -= subtrahend;
    return lhs;
}

Polar2D geometry::operator* (Polar2D lhs, double scalar)
{
    lhs *= scalar;
    return lhs;
}

Polar2D geometry::operator/(Polar2D lhs, double divisor)
{
    lhs /= divisor;
    return lhs;
}

bool geometry::operator==(const Polar2D& lhs, const Polar2D& rhs)
{
    return lhs.magnitude_ * cos(lhs.angle_) == rhs.magnitude_ * cos(rhs.angle_) &&
           lhs.magnitude_ * sin(lhs.angle_) == rhs.magnitude_ * cos(rhs.angle_);
}

bool geometry::operator!=(const Polar2D& lhs, const Polar2D& rhs)
{
    return !operator==(lhs, rhs);
}

