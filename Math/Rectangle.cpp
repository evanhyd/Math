#include "Rectangle.h"

using namespace geometry;

Rectangle::Rectangle(const Cartesian2D& new_pos, const Fraction& new_width, const Fraction& new_length) :
    Shape2D(new_pos), width_(new_width), length_(new_length)
{
    //empty
}

bool Rectangle::operator==(const Shape2D& other) const
{
    return other.equals(*this);
}
bool Rectangle::operator!=(const Shape2D& other) const
{
    return !other.equals(*this);
}

bool Rectangle::equals(const Rectangle& other) const
{
    return width_ == other.width_ && length_ == other.length_;
}


Fraction Rectangle::Perimeter() const
{
    //2 * PI * r
    return (width_ + length_) * 2ll;
}
Fraction Rectangle::Area() const
{
    //PI * r^2
    return width_ * length_;
}

bool Rectangle::IsPointInside(const Cartesian2D& point) const
{
    Cartesian2D relative = point - pos_;
    return Fraction(0ll) <= relative.GetX() && relative.GetX() <= width_ && Fraction(0ll) <= relative.GetY() && relative.GetY() <= length_;
}