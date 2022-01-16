#pragma once
#include <iostream>

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
    void operator+=(const Fraction& addend);
    void operator-=(const Fraction& subtrahend);
    void operator*=(const Fraction& scalar);
    void operator/=(const Fraction& divisor);

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

    friend Fraction pow(Fraction fraction, size_t exp); //intended to override std::pow
    friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);


//misc
public:
    bool IsInteger() const;

//private
private:
    void Reduce();
};

