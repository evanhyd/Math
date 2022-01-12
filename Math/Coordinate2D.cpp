#include "Coordinate2D.h"

Coordinate2D::Coordinate2D(Fraction new_x, Fraction new_y) : x_(new_x), y_(new_y)
{
    //empty
}

bool Coordinate2D::operator==(const Coordinate2D& other) const
{
    return x_ == other.x_ && y_ == other.y_;
}
bool Coordinate2D::operator!=(const Coordinate2D& other) const
{
    return !(*this == other);
}

void Coordinate2D::operator+=(const Coordinate2D& addend)
{
    x_ += addend.x_;
    y_ += addend.y_;
}
void Coordinate2D::operator-=(const Coordinate2D& subtrahend)
{
    x_ -= subtrahend.x_;
    y_ -= subtrahend.y_;
}
void Coordinate2D::operator*=(const Fraction& scalar)
{
    x_ *= scalar;
    y_ *= scalar;
}
void Coordinate2D::operator/=(const Fraction& divisor)
{
    x_ /= divisor;
    y_ /= divisor;
}

Coordinate2D Coordinate2D::operator+(const Coordinate2D& addend) const
{
    Coordinate2D sum = *this;
    sum += addend;
    return sum;
}
Coordinate2D Coordinate2D::operator-(const Coordinate2D& subtrahend) const
{
    Coordinate2D difference = *this;
    difference -= subtrahend;
    return difference;
}
Coordinate2D Coordinate2D::operator*(const Fraction& scalar) const
{
    Coordinate2D product = *this;
    product *= scalar;
    return product;
}
Coordinate2D Coordinate2D::operator/(const Fraction& divisor) const
{
    Coordinate2D quotient = *this;
    quotient /= divisor;
    return quotient;
}


Fraction Coordinate2D::Magnitude() const
{
    return Fraction(sqrt(x_ * x_ + y_ * y_));
}

Coordinate2D Coordinate2D::UnitVector() const
{
    return Coordinate2D(*this / this->Magnitude());
}

bool Coordinate2D::IsZero() const
{
    return x_ == 0ll && y_ == 0ll;
}

void Coordinate2D::SetZero()
{
    x_ = 0ll;
    y_ = 0ll;
}