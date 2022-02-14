#include "Vector.h"
#include "debug.h"
#include <algorithm>

using namespace matrix;

#define DEBUG_MODE false

Vector::Vector() : 
    size_(0), data_(nullptr)
{
    DEBUG_LOG("vec default constructor", DEBUG_MODE);
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

Vector::Vector(const Vector& rhs) :
    size_(rhs.size_), data_(new double[rhs.size_])
{
    DEBUG_LOG("vec copy constructor", DEBUG_MODE);
    std::copy(rhs.data_, rhs.data_ + size_, data_);
}

Vector::Vector(Vector&& rhs) noexcept : 
    Vector()
{
    DEBUG_LOG("vec move constructor", DEBUG_MODE);
    swap(*this, rhs);
}

Vector::~Vector()
{
    DEBUG_LOG("vec destructor", DEBUG_MODE);
    delete[] data_;
}

Vector& Vector::operator=(Vector rhs)
{
    DEBUG_LOG("vec copy/move assignment", DEBUG_MODE);
    matrix::swap(*this, rhs);
    return *this;
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

double& Vector::operator[](size_t i)
{
    return data_[i];
}
double Vector::operator[](size_t i) const
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

double Vector::Dot(const Vector& rhs) const
{
    if (!this->IsSameDim(rhs)) throw std::domain_error("vector dot product has different dimension");

    double dot_product = 0.0;
    for (size_t i = 0; i < size_; ++i)
    {
        dot_product += data_[i] * rhs.data_[i];
    }
    return dot_product;
}



bool Vector::IsSameDim(const Vector& rhs) const
{
    return size_ == rhs.size_;
}










Vector matrix::operator+(Vector lhs, const Vector& addend)
{
    lhs += addend;
    return lhs;
}

Vector matrix::operator-(Vector lhs, const Vector& subtrahend)
{
    lhs -= subtrahend;
    return lhs;
}

Vector matrix::operator*(Vector lhs, double scalar)
{
    lhs *= scalar;
    return lhs;
}

bool matrix::operator==(const Vector& lhs, const Vector& rhs)
{
    if (lhs.size_ != rhs.size_) return false;

    for (size_t i = 0; i < lhs.size_; ++i)
    {
        if (lhs.data_[i] != rhs.data_[i]) return false;
    }
    return true;
}

bool matrix::operator!=(const Vector& lhs, const Vector& rhs)
{
    return !operator==(lhs, rhs);
}



std::ostream& matrix::operator<<(std::ostream& output, const Vector& vec)
{
    std::for_each_n(vec.data_, vec.size_, [&output](double val) { output << val << ' '; });
    return output;
}

void matrix::swap(Vector& lhs, Vector& rhs)
{
    using std::swap;
    swap(lhs.size_, rhs.size_);
    swap(lhs.data_, rhs.data_);
}