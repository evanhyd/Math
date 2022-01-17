#pragma once
#include <iostream>

namespace matrix
{
    class Vector
    {
        //yes I know std::array will work
        size_t size_;
        double* data_;

    public:
        Vector();
        Vector(std::initializer_list<double> lst);
        explicit Vector(size_t new_dimension, double new_value = 0.0);
        Vector(const Vector& other);
        Vector(Vector&& other) noexcept;
        ~Vector();

        Vector& operator=(const Vector& other);
        Vector& operator=(Vector&& other) noexcept;

        double& operator[](size_t i);

        bool operator==(const Vector& other) const;
        bool operator!=(const Vector& other) const;

        Vector& operator+=(const Vector& addend);
        Vector& operator-=(const Vector& subtrahend);
        Vector& operator*=(double scalar);
        Vector operator+(const Vector& addend) const;
        Vector operator-(const Vector& subtrahend) const;
        Vector operator*(double scalar) const;

        double Dot(const Vector& other) const;
        bool IsZero() const;
        size_t Dim() const;

    private:
        bool IsSameDimension(const Vector& other) const;

        friend std::ostream& operator<<(std::ostream& output, const Vector& vec);
        friend void swap(Vector& v1, Vector& v2);
    };

    std::ostream& operator<<(std::ostream& output, const Vector& vec);
    void swap(Vector& v1, Vector& v2);
    
}

