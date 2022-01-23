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
        Matrix operator*(const Matrix& other) const;

        Vector& operator[](size_t i);
        const Vector& operator[](size_t i) const;


        size_t RowDim() const;
        size_t ColumnDim() const;
        bool IsZero() const;
        bool IsIdentity() const;
        bool IsSquare() const;
        bool IsSameDim(const Matrix& other) const;

        void SetZero();
        void SetIdentity();
        
        Matrix& Scale(double scalar);
        Matrix Transpose() const;

        //row operations
        Matrix& RowSwap(size_t r1, size_t r2);
        Matrix& RowMultiply(size_t r1, double scalar);
        Matrix& RowAdd(size_t srce_row, double scalar, size_t dest_row);

        //column operations
        Matrix& ColumnSwap(size_t c1, size_t c2);
        Matrix& ColumnMultiply(size_t c1, double scalar);
        Matrix& ColumnAdd(size_t srce_column, double scalar, size_t dest_column);



    private:

        static constexpr double kEpsilon = 0.0000001;

        friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
        friend void swap(Matrix& m1, Matrix& m2);
    };

    std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
    void swap(Matrix& m1, Matrix& m2);
    Matrix pow(Matrix matrix, size_t exp);
}

