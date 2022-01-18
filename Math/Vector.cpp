#include "Vector.h"
#include "debug.h"
#include <algorithm>

using namespace matrix;

#define DEBUG_MODE false

Vector::Vector() : 
    size_(0), data_(nullptr)
{
    DEBUG_LOG("vec default constructor", DEBUG_MODE);
    //empty
}
Vector::Vector(std::initializer_list<double> lst) : 
    size_(lst.size()), data_(new double[lst.size()])
{
    DEBUG_LOG("vec initializer constructor", DEBUG_MODE);
    std::move(lst.begin(), lst.end(), data_);
}
Vector::Vector(size_t new_dimension, double new_value) : 
    size_(new_dimension), data_(new double[new_dimension])
{
    DEBUG_LOG("vec direct constructor", DEBUG_MODE);
    std::fill(data_, data_ + size_, new_value);
}
Vector::Vector(const Vector& other) :
    size_(other.size_), data_(new double[other.size_])
{
    DEBUG_LOG("vec copy constructor", DEBUG_MODE);
    std::copy(other.data_, other.data_ + size_, data_);
}
Vector::Vector(Vector&& other) noexcept : 
    Vector()
{
    DEBUG_LOG("vec move constructor", DEBUG_MODE);
    swap(*this, other);
}
Vector::~Vector()
{
    DEBUG_LOG("vec destructor", DEBUG_MODE);
    delete[] data_;
}

Vector& Vector::operator=(const Vector& other)
{
    DEBUG_LOG("vec copy assignmente", DEBUG_MODE);
    Vector temp(other);
    matrix::swap(*this, temp);
    return *this;
}
Vector& Vector::operator=(Vector&& other) noexcept
{
    DEBUG_LOG("vec move assignment", DEBUG_MODE);
    Vector temp(std::move(other));
    matrix::swap(*this, temp);
    return *this;
}


bool Vector::operator==(const Vector& other) const
{
    if (size_ != other.size_) return false;

    for (size_t i = 0; i < size_; ++i)
    {
        if (data_[i] != other.data_[i]) return false;
    }   
    return true;
}
bool Vector::operator!=(const Vector& other) const
{
    return !(*this == other);
}

Vector& Vector::operator+=(const Vector& addend)
{
    if (!this->IsSameDim(addend)) throw std::domain_error("addend vector addend has different dimension");

    for (size_t i = 0; i < size_; ++i)
    {
        data_[i] += addend.data_[i];
    }
    return *this;
}
Vector& Vector::operator-=(const Vector& subtrahend)
{
    if (!this->IsSameDim(subtrahend)) throw std::domain_error("subtrahend vector subtrahend has different dimension");

    for (size_t i = 0; i < size_; ++i)
    {
        data_[i] -= subtrahend.data_[i];
    }
    return *this;
}
Vector& Vector::operator*=(double scalar)
{
    std::for_each(data_, data_ + size_, [scalar](double& num) { num *= scalar; });
    return *this;
}

Vector Vector::operator+(const Vector& addend) const
{
    Vector sum(*this);
    sum += addend;
    return sum;
}
Vector Vector::operator-(const Vector& subtrahend) const
{
    Vector difference(*this);
    difference -= subtrahend;
    return difference;
}
Vector Vector::operator*(double scalar) const
{
    Vector scalar_product(*this);
    scalar_product *= scalar;
    return scalar_product;
}

double& Vector::operator[](size_t i)
{
    return data_[i];
}


size_t Vector::Dim() const
{
    return size_;
}
bool Vector::IsZero() const
{
    for (size_t i = 0; i < size_; ++i)
    {
        if (data_[i] != 0.0) return false;
    }
    return true;
}
void Vector::SetZero()
{
    for (size_t i = 0; i < size_; ++i)
    {
        data_[i] = 0.0;
    }
}

double Vector::Dot(const Vector& other) const
{
    if (!this->IsSameDim(other)) throw std::domain_error("vector dot product has different dimension");

    double dot_product = 0.0;
    for (size_t i = 0; i < size_; ++i)
    {
        dot_product += data_[i] * other.data_[i];
    }
    return dot_product;
}



bool Vector::IsSameDim(const Vector& other) const
{
    return size_ == other.size_;
}













std::ostream& matrix::operator<<(std::ostream& output, const Vector& vec)
{
    std::for_each_n(vec.data_, vec.size_, [&output](double val) { output << val << ' '; });
    return output;
}

void matrix::swap(Vector& v1, Vector& v2)
{
    using std::swap;
    swap(v1.size_, v2.size_);
    swap(v1.data_, v2.data_);
}