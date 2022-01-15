#include "Polar2D.h"
#include <cmath>

using namespace geometry;

Polar2D::Polar2D(const Fraction& new_magnitude, const Fraction& new_angle) : magnitude_(new_magnitude), angle_(new_angle)
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
    Fraction x = magnitude_ * cos(double(angle_)) + addend.magnitude_ * cos(double(addend.angle_));
    Fraction y = magnitude_ * sin(double(angle_)) + addend.magnitude_ * sin(double(addend.angle_));

    magnitude_ = sqrt(x * x + y * y);
    angle_ = atan2(double(y), double(x));
}
void Polar2D::operator-=(const Polar2D& subtrahend)
{
    Fraction x = magnitude_ * cos(double(angle_)) - subtrahend.magnitude_ * cos(double(subtrahend.angle_));
    Fraction y = magnitude_ * sin(double(angle_)) - subtrahend.magnitude_ * sin(double(subtrahend.angle_));

    magnitude_ = sqrt(x * x + y * y);
    angle_ = atan2(double(y), double(x));
}
void Polar2D::operator*=(const Fraction& scalar)
{
    magnitude_ *= scalar;
}
void Polar2D::operator/=(const Fraction& divisor)
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
Polar2D Polar2D::operator* (const Fraction& scalar) const
{
    Polar2D product = *this;
    product *= scalar;
    return product;
}
Polar2D Polar2D::operator/(const Fraction& divisor) const
{
    Polar2D quotient = *this;
    quotient /= divisor;
    return quotient;
}


const Fraction& Polar2D::GetMagnitude() const
{
    return magnitude_;
}
const Fraction& Polar2D::GetAngle() const
{
    return angle_;
}
void Polar2D::SetMagnitude(const Fraction& new_magnitude)
{
    magnitude_ = new_magnitude;
}
void Polar2D::SetAngle(const Fraction& new_angle)
{
    angle_ = new_angle;
}

Polar2D Polar2D::UnitPolar() const
{
    return Polar2D(Fraction(1ll), angle_);
}
bool Polar2D::IsZero() const
{
    return magnitude_ == 0ll;
}