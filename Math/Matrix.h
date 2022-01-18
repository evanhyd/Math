#pragma once
#include <iostream>
#include "Vector.h"

namespace matrix
{
    class Matrix
    {
        size_t row_size_;
        size_t column_size_;
        Vector* data_;

    public:
        Matrix();
        Matrix(std::initializer_list<Vector> lst);
        explicit Matrix(size_t new_row_size, size_t new_column_size, double new_value = 0.0);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        ~Matrix();

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        bool operator==(const Matrix& other) const;
        bool operator!=(const Matrix& other) const;
        Matrix& operator+=(const Matrix& addend);
        Matrix& operator-=(const Matrix& subtrahend);
        Matrix operator+(const Matrix& addend) const;
        Matrix operator-(const Matrix& subtrahend) const;

        Vector& operator[](size_t i);


        size_t RowDim() const;
        size_t ColumnDim() const;
        bool IsZero() const;
        void SetZero();
        bool IsStandard() const;

        bool IsSameDim(const Matrix& other) const;

    private:

        friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
        friend void swap(Matrix& m1, Matrix& m2);
    };

    std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
    void swap(Matrix& m1, Matrix& m2);
}

