#include "Rectangle.h"

using namespace geometry;

Rectangle::Rectangle(const Cartesian2D& new_pos, double new_width, double new_length) :
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


double Rectangle::Perimeter() const
{
    //2 * PI * r
    return (width_ + length_) * 2ll;
}
double Rectangle::Area() const
{
    //PI * r^2
    return width_ * length_;
}

bool Rectangle::IsPointInside(const Cartesian2D& point) const
{
    Cartesian2D relative = point - pos_;
    return 0.0 <= relative.X() && relative.X() <= width_ && 0.0 <= relative.Y() && relative.Y() <= length_;
}