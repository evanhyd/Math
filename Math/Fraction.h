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
        explicit operator double() const;


        bool IsInteger() const;

    private:
        void Reduce();

        friend Fraction operator+(Fraction lhs, const Fraction& addend);
        friend Fraction operator-(Fraction lhs, const Fraction& difference);
        friend Fraction operator*(Fraction lhs, const Fraction& scalar);
        friend Fraction operator/(Fraction lhs, const Fraction& divisor);
        friend bool operator==(const Fraction& lhs, const Fraction& rhs);
        friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
        friend bool operator<(const Fraction& lhs, const Fraction& rhs);
        friend bool operator>(const Fraction& lhs, const Fraction& rhs);
        friend bool operator>=(const Fraction& lhs, const Fraction& rhs);
        friend bool operator<=(const Fraction& lhs, const Fraction& rhs);
        friend Fraction pow(Fraction fraction, int exp);
        friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
    };

    Fraction operator+(Fraction lhs, const Fraction& addend);
    Fraction operator-(Fraction lhs, const Fraction& difference);
    Fraction operator*(Fraction lhs, const Fraction& scalar);
    Fraction operator/(Fraction lhs, const Fraction& divisor);
    bool operator==(const Fraction& lhs, const Fraction& rhs);
    bool operator!=(const Fraction& lhs, const Fraction& rhs);
    bool operator<(const Fraction& lhs, const Fraction& rhs);
    bool operator>(const Fraction& lhs, const Fraction& rhs);
    bool operator>=(const Fraction& lhs, const Fraction& rhs);
    bool operator<=(const Fraction& lhs, const Fraction& rhs);

    Fraction pow(Fraction fraction, int exp);
    std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
}