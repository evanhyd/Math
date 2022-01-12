#pragma once
#include "Fraction.h"

class Shape3D
{
    Shape3D() = default;

    virtual Fraction SurfaceArea() const = 0;
    virtual Fraction Volume() const = 0;
};

