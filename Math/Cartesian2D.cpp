#include "Cartesian2D.h"
#include <cmath>

using namespace geometry;

Cartesian2D::Cartesian2D(double new_x, double new_y) : x_(new_x), y_(new_y)
{
    //empty
}

Cartesian2D& Cartesian2D::operator+=(const Cartesian2D& addend)
{
    x_ += addend.x_;
    y_ += addend.y_;
    return *this;
}
Cartesian2D& Cartesian2D::operator-=(const Cartesian2D& subtrahend)
{
    x_ -= subtrahend.x_;
    y_ -= subtrahend.y_;
    return *this;
}
Cartesian2D& Cartesian2D::operator*=(double scalar)
{
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}
Cartesian2D& Cartesian2D::operator/=(double divisor)
{
    x_ /= divisor;
    y_ /= divisor;
    return *this;
}


double Cartesian2D::X() const
{
    return x_;
}

double& Cartesian2D::X()
{
    return x_;
}

double Cartesian2D::Y() const
{
    return y_;
}

double& Cartesian2D::Y()
{
    return y_;
}



double Cartesian2D::Magnitude() const
{
    return hypot(x_, y_);
}

Cartesian2D Cartesian2D::UnitVector() const
{
    return Cartesian2D(*this / this->Magnitude());
}

bool Cartesian2D::IsZero() const
{
    return x_ == 0.0 && y_ == 0.0;
}

void Cartesian2D::SetZero()
{
    x_ = 0.0;
    y_ = 0.0;
}


Cartesian2D geometry::operator+(Cartesian2D lhs, const Cartesian2D& addend)
{
    lhs += addend;
    return lhs;
}

Cartesian2D geometry::operator-(Cartesian2D lhs, const Cartesian2D& subtrahend)
{
    lhs -= subtrahend;
    return lhs;
}

Cartesian2D geometry::operator*(Cartesian2D lhs, double scalar)
{
    lhs *= scalar;
    return lhs;
}

Cartesian2D geometry::operator/(Cartesian2D lhs, double divisor)
{
    lhs /= divisor;
    return lhs;
}

bool geometry::operator==(const Cartesian2D& lhs, const Cartesian2D& rhs)
{
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

bool geometry::operator!=(const Cartesian2D& lhs, const Cartesian2D& rhs)
{
    return !operator==(lhs, rhs);
}
