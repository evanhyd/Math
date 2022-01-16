#include "Fraction.h"
#include <stdexcept>
#include <numeric>


Fraction::Fraction(ValueType new_numerator, ValueType new_denominator) : numerator_(new_numerator), denominator_(new_denominator)
{
    if (new_denominator == 0) throw std::runtime_error("Invalid denominator value: 0");
    this->Reduce();
}

void Fraction::operator+=(const Fraction& addend)
{
    ValueType lcd = std::lcm(denominator_, addend.denominator_);
    ValueType scalar1 = lcd / denominator_;
    ValueType scalar2 = lcd / addend.denominator_;

    numerator_ = numerator_ * scalar1 + addend.numerator_ * scalar2;
    denominator_ = lcd;

    this->Reduce();
}
void Fraction::operator-=(const Fraction& subtrahend)
{
    ValueType lcd = std::lcm(denominator_, subtrahend.denominator_);
    ValueType scalar1 = lcd / denominator_;
    ValueType scalar2 = lcd / subtrahend.denominator_;

    numerator_ = numerator_ * scalar1 - subtrahend.numerator_ * scalar2;
    denominator_ = lcd;

    this->Reduce();
}
void Fraction::operator*=(const Fraction& scalar)
{
    numerator_ *= scalar.numerator_;
    denominator_ *= scalar.denominator_;

    this->Reduce();
}
void Fraction::operator/=(const Fraction& divisor)
{
    if(divisor.numerator_ == 0) throw std::runtime_error("Invalid denominator value: 0");

    numerator_ *= divisor.denominator_;
    denominator_ *= divisor.numerator_;

    this->Reduce();
}

Fraction Fraction::operator+(const Fraction& addend) const
{
    Fraction sum = *this;
    sum += addend;
    return sum;
}
Fraction Fraction::operator-(const Fraction& subtrahend) const
{
    Fraction difference = *this;
    difference -= subtrahend;
    return difference;
}
Fraction Fraction::operator*(const Fraction& scalar) const
{
    Fraction product = *this;
    product *= scalar;
    return product;
}
Fraction Fraction::operator/(const Fraction& divisor) const
{
    Fraction quotient = *this;
    quotient /= divisor;
    return quotient;
}

bool Fraction::operator==(const Fraction& other) const
{
    return numerator_ == other.numerator_ && denominator_ == other.denominator_;
}
bool Fraction::operator!=(const Fraction& other) const
{
    return !(*this == other);
}
bool Fraction::operator<(const Fraction& other) const
{
    ValueType lcm = std::lcm(denominator_, other.denominator_);
    ValueType scalar1 = lcm / denominator_;
    ValueType scalar2 = lcm / other.denominator_;

    return numerator_ * scalar1 < other.numerator_* scalar2;
}
bool Fraction::operator>(const Fraction& other) const
{
    ValueType lcm = std::lcm(denominator_, other.denominator_);
    ValueType scalar1 = lcm / denominator_;
    ValueType scalar2 = lcm / other.denominator_;

    return numerator_ * scalar1 > other.numerator_* scalar2;
}
bool Fraction::operator>=(const Fraction& other) const
{
    return !(*this < other);
}
bool Fraction::operator<=(const Fraction& other) const
{
    return !(*this > other);
}


Fraction pow(Fraction fraction, size_t exp)
{
    Fraction power(1ll, 1ll);

    while (exp > 0)
    {
        if (exp & 1) power *= fraction;
        fraction *= fraction;
        exp >>= 1;
    }

    return power;
}

Fraction::operator double() const
{
    return static_cast<double>(numerator_) / denominator_;
}

std::ostream& operator<<(std::ostream& output, const Fraction& fraction)
{
    if (fraction.numerator_ != 0 && fraction.denominator_ != 1) output << fraction.numerator_ << '/' << fraction.denominator_;
    else output << std::fixed << fraction.numerator_;

    return output;
}


//misc
bool Fraction::IsInteger() const
{
    return denominator_ == 1;
}



//private
void Fraction::Reduce()
{
    if (denominator_ < 0)
    {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }

    if (numerator_ != 0)
    {
        ValueType gcd = std::gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
    }
}