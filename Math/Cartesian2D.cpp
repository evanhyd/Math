#include "Cartesian2D.h"

using namespace geometry;

Cartesian2D::Cartesian2D(const Fraction& new_x, const Fraction& new_y) : x_(new_x), y_(new_y)
{
    //empty
}

bool Cartesian2D::operator==(const Cartesian2D& other) const
{
    return x_ == other.x_ && y_ == other.y_;
}
bool Cartesian2D::operator!=(const Cartesian2D& other) const
{
    return !(*this == other);
}

void Cartesian2D::operator+=(const Cartesian2D& addend)
{
    x_ += addend.x_;
    y_ += addend.y_;
}
void Cartesian2D::operator-=(const Cartesian2D& subtrahend)
{
    x_ -= subtrahend.x_;
    y_ -= subtrahend.y_;
}
void Cartesian2D::operator*=(const Fraction& scalar)
{
    x_ *= scalar;
    y_ *= scalar;
}
void Cartesian2D::operator/=(const Fraction& divisor)
{
    x_ /= divisor;
    y_ /= divisor;
}

Cartesian2D Cartesian2D::operator+(const Cartesian2D& addend) const
{
    Cartesian2D sum = *this;
    sum += addend;
    return sum;
}
Cartesian2D Cartesian2D::operator-(const Cartesian2D& subtrahend) const
{
    Cartesian2D difference = *this;
    difference -= subtrahend;
    return difference;
}
Cartesian2D Cartesian2D::operator*(const Fraction& scalar) const
{
    Cartesian2D product = *this;
    product *= scalar;
    return product;
}
Cartesian2D Cartesian2D::operator/(const Fraction& divisor) const
{
    Cartesian2D quotient = *this;
    quotient /= divisor;
    return quotient;
}



const Fraction& Cartesian2D::GetX() const
{
    return x_;
}
const Fraction& Cartesian2D::GetY() const
{
    return y_;
}
void Cartesian2D::SetX(const Fraction& new_x)
{
    x_ = new_x;
}
void Cartesian2D::SetY(const Fraction& new_y)
{
    y_ = new_y;
}






Fraction Cartesian2D::Magnitude() const
{
    return Fraction(sqrt(x_ * x_ + y_ * y_));
}

Cartesian2D Cartesian2D::UnitVector() const
{
    return Cartesian2D(*this / this->Magnitude());
}

bool Cartesian2D::IsZero() const
{
    return x_ == 0ll && y_ == 0ll;
}

void Cartesian2D::SetZero()
{
    x_ = 0ll;
    y_ = 0ll;
}