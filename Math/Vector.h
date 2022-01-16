#pragma once
#include "Fraction.h"

namespace matrix
{
    class Vector
    {
        //yes I know std::array will work
        double* data_;
        int size_;

    public:
        Vector(int new_dimension, double new_value = 0.0);

        //big 5
        Vector(const Vector& other);
        Vector(Vector&& other) noexcept;
        ~Vector();
        void operator=(const Vector& other);
        void operator=(Vector&& other) noexcept;


    };
}

