#include "Shape2D.h"

using namespace geometry;

Shape2D::Shape2D(const Cartesian2D& new_pos) : pos_(new_pos)
{
    //empty
}

bool Shape2D::equals(const Circle& other) const
{
    return false;
}
bool Shape2D::equals(const Rectangle& other) const
{
    return false;
}