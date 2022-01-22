#pragma once

namespace geometry
{
    class Shape3D
    {
        Shape3D() = default;

        virtual double SurfaceArea() const = 0;
        virtual double Volume() const = 0;
    };
}


