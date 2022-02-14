#pragma once
#include <iostream>

namespace matrix
{
    class Vector
    {
        size_t size_;
        double* data_;

    public:
        Vector();
        Vector(std::initializer_list<double> lst);
        explicit Vector(size_t new_dimension, double new_value = 0.0);
        Vector(const Vector& rhs);
        Vector(Vector&& rhs) noexcept;
        ~Vector();

        Vector& operator=(Vector rhs);

        Vector& operator+=(const Vector& addend);
        Vector& operator-=(const Vector& subtrahend);
        Vector& operator*=(double scalar);

        double& operator[](size_t i);
        double operator[](size_t i) const;

        size_t Dim() const;
        bool IsZero() const;
        void SetZero();

        double Dot(const Vector& other) const;

    private:
        bool IsSameDim(const Vector& other) const;


        friend Vector operator+(Vector lhs, const Vector& addend);
        friend Vector operator-(Vector lhs, const Vector& subtrahend);
        friend Vector operator*(Vector lhs, double scalar);
        friend bool operator==(const Vector& lhs, const Vector& rhs);
        friend bool operator!=(const Vector& lhs, const Vector& rhs);

        friend std::ostream& operator<<(std::ostream& output, const Vector& vec);
        friend void swap(Vector& v1, Vector& v2);
    };


    Vector operator+(Vector lhs, const Vector& addend);
    Vector operator-(Vector lhs, const Vector& subtrahend);
    Vector operator*(Vector lhs, double scalar);
    bool operator==(const Vector& lhs, const Vector& rhs);
    bool operator!=(const Vector& lhs, const Vector& rhs);

    std::ostream& operator<<(std::ostream& output, const Vector& vec);
    void swap(Vector& lhs, Vector& rhs);
    
}

