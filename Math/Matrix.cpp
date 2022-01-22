#include "Matrix.h"
#include "debug.h"
#include <algorithm>

#define DEBUG_MODE false

using namespace matrix;


Matrix::Matrix() :
    row_size_(0), column_size_(0), data_(nullptr)
{
    // empty
    DEBUG_LOG("matrix default constructor", DEBUG_MODE);
}
Matrix::Matrix(std::initializer_list<Vector> lst) : 
    row_size_(lst.size()), column_size_(lst.begin()->Dim()), data_(new Vector[lst.size()])
{
    DEBUG_LOG("matrix list constructor", DEBUG_MODE);
    std::move(lst.begin(), lst.end(), data_);
}
Matrix::Matrix(size_t new_row_size, size_t new_column_size, double new_value) :
    row_size_(new_row_size), column_size_(new_column_size), data_(new Vector[new_row_size])
{
    DEBUG_LOG("matrix direct constructor", DEBUG_MODE);
    std::for_each(data_, data_ + row_size_, [this, new_value](Vector& vec) {vec = std::move(Vector(this->column_size_, new_value)); });
}
Matrix::Matrix(const Matrix& other) :
    row_size_(other.row_size_), column_size_(other.column_size_), data_(new Vector[other.row_size_])
{
    DEBUG_LOG("matrix copy constructor", DEBUG_MODE);
    std::copy(other.data_, other.data_ + row_size_, data_);
}
Matrix::Matrix(Matrix&& other) noexcept :
    Matrix()
{
    DEBUG_LOG("matrix move constructor", DEBUG_MODE);
    swap(*this, other);
}
Matrix::~Matrix()
{
    DEBUG_LOG("matrix destructor", DEBUG_MODE);
    delete[] data_;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    DEBUG_LOG("matrix copy assignment", DEBUG_MODE);
    Matrix temp(other);
    swap(*this, temp);
    return *this;
}
Matrix& Matrix::operator=(Matrix&& other) noexcept
{
    DEBUG_LOG("matrix move assignment", DEBUG_MODE);
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
    if (!this->IsSameDim(addend)) throw std::domain_error("error, addend matrix has invalid dimension");
    for (size_t x = 0; x < row_size_; ++x)
    {
        data_[x] += addend.data_[x];
    }

    return *this;
}
Matrix& Matrix::operator-=(const Matrix& subtrahend)
{
    if (!this->IsSameDim(subtrahend)) throw std::domain_error("error, subtrahend matrix has invalid dimension");
    for (size_t x = 0; x < row_size_; ++x)
    {
        data_[x] -= subtrahend.data_[x];
    }

    return *this;
}
Matrix Matrix::operator+(const Matrix& addend) const
{
    Matrix sum(*this);
    sum += addend;
    return sum;
}
Matrix Matrix::operator-(const Matrix& subtrahend) const
{
    Matrix difference(*this);
    difference -= subtrahend;
    return difference;
}
Matrix Matrix::operator*(const Matrix& other) const
{
    //ij * jy = iy
    if (column_size_ != other.row_size_) throw std::domain_error("error, matrix multiplication operand has invalid dimension");

    Matrix product(row_size_, other.column_size_, 0.0);

    for (int x = 0; x < product.row_size_; ++x)
    {
        for (int y = 0; y < product.column_size_; ++y)
        {
            for (int i = 0; i < column_size_; ++i)
            {
                product.data_[x][y] += data_[x][i] * other.data_[i][y];
            }
        }
    }

    return product;
}

Vector& Matrix::operator[](size_t i)
{
    return data_[i];
}


size_t Matrix::RowDim() const
{
    return row_size_;
}
size_t Matrix::ColumnDim() const
{
    return column_size_;
}
bool Matrix::IsZero() const
{
    for (size_t x = 0; x < row_size_; ++x)
    {
        if (!data_[x].IsZero()) return false;
    }

    return true;
}
bool Matrix::IsSquare() const
{
    return row_size_ == column_size_;
}
bool Matrix::IsIdentity() const
{
    if (!this->IsSquare()) return false;

    for (size_t x = 0; x < row_size_; ++x)
    {
        for (size_t y = 0; y < column_size_; ++y)
        {
            if (x == y && abs(data_[x][y] - 1.0) > kEpsilon) return false;
            else if (x != y && abs(data_[x][y]) > kEpsilon) return false;
        }
    }

    return true;
}
bool Matrix::IsSameDim(const Matrix& other) const
{
    return row_size_ == other.row_size_ && column_size_ == other.column_size_;
}



void Matrix::SetZero()
{
    for (size_t x = 0; x < row_size_; ++x)
    {
        data_[x].SetZero();
    }
}
void Matrix::SetIdentity()
{
    if (!this->IsSquare()) throw std::domain_error("error, operand is not a square matrix");
    
    for (size_t i = 0; i < row_size_; ++i)
    {
        for (size_t j = 0; j < column_size_; ++j)
        {
            if (i == j) data_[i][j] = 1.0;
            else data_[i][j] = 0.0;
        }
    }
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
Matrix matrix::pow(Matrix matrix, size_t exp)
{
    Matrix power(matrix.RowDim(), matrix.ColumnDim());
    power.SetIdentity();

    while (exp > 0)
    {
        if (exp & 1) power = power * matrix;
        matrix = matrix * matrix;
        exp >>= 1;
    }

    return power;
}