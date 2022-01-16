#include "Polar2D.h"
#include <cmath>

using namespace geometry;

Polar2D::Polar2D(double new_magnitude, double new_angle) : magnitude_(new_magnitude), angle_(new_angle)
{
    //empty
}

bool Polar2D::operator==(const Polar2D& other) const
{
    return magnitude_ == other.magnitude_ && angle_ == other.angle_;
}
bool Polar2D::operator!=(const Polar2D& other) const
{
    return  !(*this == other);
}
     
void Polar2D::operator+=(const Polar2D& addend)
{
    double x = magnitude_ * cos(angle_) + addend.magnitude_ * cos(addend.angle_);
    double y = magnitude_ * sin(angle_) + addend.magnitude_ * sin(addend.angle_);

    magnitude_ = hypot(x, y);
    angle_ = atan2(y, x);
}
void Polar2D::operator-=(const Polar2D& subtrahend)
{
    double x = magnitude_ * cos(angle_) - subtrahend.magnitude_ * cos(subtrahend.angle_);
    double y = magnitude_ * sin(angle_) - subtrahend.magnitude_ * sin(subtrahend.angle_);

    magnitude_ = hypot(x, y);
    angle_ = atan2(y, x);
}
void Polar2D::operator*=(double scalar)
{
    magnitude_ *= scalar;
}
void Polar2D::operator/=(double divisor)
{
    magnitude_ /= divisor;
}

Polar2D Polar2D::operator+ (const Polar2D& addend) const
{
    Polar2D sum = *this;
    sum += addend;
    return sum;
}
Polar2D Polar2D::operator- (const Polar2D& subtrahend) const
{
    Polar2D difference = *this;
    difference -= subtrahend;
    return difference;
}
Polar2D Polar2D::operator* (double scalar) const
{
    Polar2D product = *this;
    product *= scalar;
    return product;
}
Polar2D Polar2D::operator/(double divisor) const
{
    Polar2D quotient = *this;
    quotient /= divisor;
    return quotient;
}


double Polar2D::GetMagnitude() const
{
    return magnitude_;
}
double Polar2D::GetAngle() const
{
    return angle_;
}
void Polar2D::SetMagnitude(double new_magnitude)
{
    magnitude_ = new_magnitude;
}
void Polar2D::SetAngle(double new_angle)
{
    angle_ = new_angle;
}

Polar2D Polar2D::UnitPolar() const
{
    return Polar2D(1.0, angle_);
}
bool Polar2D::IsZero() const
{
    return magnitude_ == 0.0;
}