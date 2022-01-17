#include "Matrix.h"
#include <algorithm>

using namespace matrix;

Matrix::Matrix() :
    row_size_(0), column_size_(0), data_(nullptr)
{
    //empty
}
Matrix::Matrix(std::initializer_list<Vector> lst) : 
    row_size_(lst.size()), column_size_(lst.begin()->Dim()), data_(new Vector[lst.size()])
{
    std::move(lst.begin(), lst.end(), data_);
}
Matrix::Matrix(size_t new_row_size, size_t new_column_size, double new_value) :
    row_size_(new_row_size), column_size_(new_column_size), data_(new Vector[new_row_size])
{
    std::for_each_n(data_, row_size_, [this, new_value](Vector& vec) {vec = std::move(Vector(this->column_size_, new_value)); });
}
Matrix::Matrix(const Matrix& other) :
    row_size_(other.row_size_), column_size_(other.column_size_)
{
    data_ = new Vector[row_size_];
    std::copy_n(other.data_, row_size_, data_);
}
Matrix::Matrix(Matrix&& other) noexcept :
    row_size_(other.row_size_), column_size_(other.column_size_), data_(other.data_)
{
    other.data_ = nullptr;
}
Matrix::~Matrix()
{
    delete[] data_;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    Matrix temp(other);
    swap(*this, temp);
    return *this;
}
Matrix& Matrix::operator=(Matrix&& other) noexcept
{
    Matrix temp(std::move(other));
    swap(*this, temp);
    return *this;
}


bool Matrix::operator==(const Matrix& other) const
{
    if (row_size_ != other.row_size_ || column_size_ != other.column_size_) return false;

    for (size_t x = 0; x < row_size_; ++x)
    {
        if (data_[x] != other.data_[x]) return false;
    }

    return true;
}
bool Matrix::operator!=(const Matrix& other) const
{
    return !(*this == other);
}
Matrix& Matrix::operator+=(const Matrix& addend)
{
    if (!this->IsSameDimension(addend)) throw std::domain_error("addend matrix has different dimension");
    for (size_t x = 0; x < row_size_; ++x)
    {
        data_[x] += addend.data_[x];
    }

    return *this;
}
Matrix& Matrix::operator-=(const Matrix& subtrahend)
{
    if (!this->IsSameDimension(subtrahend)) throw std::domain_error("subtrahend matrix has different dimension");
    for (size_t x = 0; x < row_size_; ++x)
    {
        data_[x] -= subtrahend.data_[x];
    }

    return *this;
}
Matrix Matrix::operator+(const Matrix& addend) const
{
    Matrix sum(*this);
    return sum += addend;
}
Matrix Matrix::operator-(const Matrix& subtrahend) const
{
    Matrix difference(*this);
    return difference -= subtrahend;
}



bool Matrix::IsZero() const
{
    for (size_t x = 0; x < row_size_; ++x)
    {
        if (!data_[x].IsZero()) return false;
    }

    return true;
}















bool Matrix::IsSameDimension(const Matrix& other) const
{
    return row_size_ == other.row_size_ && column_size_ == other.column_size_;
}


std::ostream& matrix::operator<<(std::ostream& output, const Matrix& matrix)
{
    for (size_t x = 0; x < matrix.row_size_; ++x)
    {
        for (size_t y = 0; y < matrix.column_size_; ++y)
        {
            output << matrix.data_[x][y] << ' ';
        }
        output << '\n';
    }
    return output;
}
void matrix::swap(Matrix& m1, Matrix& m2)
{
    using std::swap;
    swap(m1.row_size_, m2.row_size_);
    swap(m1.column_size_, m2.column_size_);
    swap(m1.data_, m2.data_);
}