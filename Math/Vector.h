#pragma once
#include "Fraction.h"

namespace matrix
{
    class Vector
    {
        Fraction* data_;
        int size_;

    public:
        Vector(int new_dimension, const Fraction& new_value = 0ll);
    };
}

