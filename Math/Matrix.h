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
        Matrix(const Matrix& rhs);
        Matrix(Matrix&& rhs) noexcept;
        ~Matrix();

        Matrix& operator=(Matrix rhs);

        
        Matrix& operator+=(const Matrix& addend);
        Matrix& operator-=(const Matrix& subtrahend);

        Vector& operator[](size_t i);
        const Vector& operator[](size_t i) const;


        size_t RowDim() const;
        size_t ColumnDim() const;
        bool IsZero() const;
        bool IsIdentity() const;
        bool IsSquare() const;
        bool IsSameDim(const Matrix& rhs) const;

        void SetZero();
        void SetIdentity();
        
        Matrix Multiply(const Matrix& rhs) const;
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


        friend Matrix operator+(Matrix lhs, const Matrix& addend);
        friend Matrix operator-(Matrix lhs, const Matrix& subtrahend);
        friend bool operator==(const Matrix& lhs, const Matrix& rhs);
        friend bool operator!=(const Matrix& lhs, const Matrix& rhs);

        friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
        friend void swap(Matrix& m1, Matrix& m2);
    };


    Matrix operator+(Matrix lhs, const Matrix& addend);
    Matrix operator-(Matrix lhs, const Matrix& subtrahend);
    bool operator==(const Matrix& lhs, const Matrix& rhs);
    bool operator!=(const Matrix& lhs, const Matrix& rhs);

    std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
    void swap(Matrix& lhs, Matrix& rhs);
    Matrix pow(Matrix matrix, size_t exp);
}

