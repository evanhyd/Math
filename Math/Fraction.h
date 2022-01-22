#pragma once
#include <iostream>

namespace number
{
    class Fraction
    {
    public:
        using ValueType = long long;

    private:
        ValueType numerator_;
        ValueType denominator_;

    public:

        explicit Fraction(ValueType new_numerator, ValueType new_denominator);

        //arithmetic
        Fraction& operator+= (const Fraction& addend);
        Fraction& operator-= (const Fraction& subtrahend);
        Fraction& operator*= (const Fraction& scalar);
        Fraction& operator/=(const Fraction& divisor);

        Fraction operator+(const Fraction& addend) const;
        Fraction operator-(const Fraction& difference) const;
        Fraction operator*(const Fraction& scalar) const;
        Fraction operator/(const Fraction& divisor) const;

        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        explicit operator double() const;

        bool IsInteger() const;

    private:
        void Reduce();


        friend Fraction pow(Fraction fraction, size_t exp); //intended to override std::pow
        friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
    };

    Fraction pow(Fraction fraction, size_t exp); //intended to override std::pow
    std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
}