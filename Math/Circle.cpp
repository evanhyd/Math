#include "Circle.h"
#include <numbers>

using namespace geometry;

Circle::Circle(const Cartesian2D& new_pos, const Fraction& new_radius) : Shape2D(new_pos), radius_(new_radius)
{
    //empty
}

bool Circle::operator==(const Shape2D& other) const
{
    return other.equals(*this);
}
bool Circle::operator!=(const Shape2D& other) const
{
    return !(*this == other);
}

bool Circle::equals(const Circle& other) const
{
    return radius_ == other.radius_;
}


Fraction Circle::Perimeter() const
{
    //2 * PI * r
    return Fraction(2ll) * Fraction(std::numbers::pi) * radius_;
}
Fraction Circle::Area() const
{
    //PI * r^2
    return Fraction(std::numbers::pi) * radius_ * radius_;
}

bool Circle::IsPointInside(const Cartesian2D& point) const
{
    return (point - pos_).Magnitude() <= radius_;
}