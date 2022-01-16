#include "Vector.h"
#include <algorithm>

using namespace matrix;

Vector::Vector(int new_dimension, double new_value) : size_(new_dimension)
{
    data_ = new double[size_];
    std::fill_n(data_, size_, new_value);
}


Vector::Vector(const Vector& other)
{
    *this = other;
}
Vector::Vector(Vector&& other) noexcept
{
    *this = std::move(other);
}
Vector::~Vector()
{
    delete[] data_;
}
void Vector::operator=(const Vector& other)
{
    //clean up the old data
    delete[] data_;

    size_ = other.size_;
    data_ = new double[size_];
    std::copy_n(other.data_, size_, data_);
}
void Vector::operator=(Vector&& other) noexcept
{
    size_ = other.size_;
    std::swap(data_, other.data_);
}