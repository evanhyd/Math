#include "Fraction.h"
#include <stdexcept>
#include <numeric>

using namespace number;

Fraction::Fraction(ValueType new_numerator, ValueType new_denominator) : numerator_(new_numerator), denominator_(new_denominator)
{
    if (new_denominator == 0) throw std::runtime_error("Invalid denominator value: 0");
    this->Reduce();
}

Fraction& Fraction::operator+=(const Fraction& addend)
{
    ValueType lcd = std::lcm(denominator_, addend.denominator_);

    //calculate the numerator with the lowest common denominator base
    numerator_ = numerator_ * (lcd / denominator_) + addend.numerator_ * (lcd / addend.denominator_);
    denominator_ = lcd;

    this->Reduce();
    return *this;
}
Fraction& Fraction::operator-=(const Fraction& subtrahend)
{
    ValueType lcd = std::lcm(denominator_, subtrahend.denominator_);
    ValueType scalar1 = lcd / denominator_;
    ValueType scalar2 = lcd / subtrahend.denominator_;

    numerator_ = numerator_ * scalar1 - subtrahend.numerator_ * scalar2;
    denominator_ = lcd;

    this->Reduce();
    return *this;
}
Fraction& Fraction::operator*=(const Fraction& scalar)
{
    numerator_ *= scalar.numerator_;
    denominator_ *= scalar.denominator_;

    this->Reduce();
    return *this;
}
Fraction& Fraction::operator/=(const Fraction& divisor)
{
    if(divisor.numerator_ == 0) throw std::runtime_error("Invalid denominator value: 0");

    numerator_ *= divisor.denominator_;
    denominator_ *= divisor.numerator_;

    this->Reduce();
    return *this;
}

Fraction::operator double() const
{
    return static_cast<double>(numerator_) / denominator_;
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
    else
    {
        denominator_ = 1;
    }
}







Fraction number::operator+(Fraction lhs, const Fraction& addend)
{
    lhs += addend;
    return lhs;
}
Fraction number::operator-(Fraction lhs, const Fraction& difference)
{
    lhs -= difference;
    return lhs;
}
Fraction number::operator*(Fraction lhs, const Fraction& scalar)
{
    lhs *= scalar;
    return lhs;
}
Fraction number::operator/(Fraction lhs, const Fraction& divisor)
{
    lhs /= divisor;
    return lhs;
}
bool number::operator==(const Fraction& lhs, const Fraction& rhs)
{
    return lhs.numerator_ * rhs.denominator_ == rhs.numerator_ * lhs.denominator_;
}
bool number::operator!=(const Fraction& lhs, const Fraction& rhs)
{
    return !operator==(lhs, rhs);
}
bool number::operator<(const Fraction& lhs, const Fraction& rhs)
{
    return lhs.numerator_* rhs.denominator_ < rhs.numerator_ * lhs.denominator_;
}
bool number::operator>(const Fraction& lhs, const Fraction& rhs)
{
    return operator<(rhs, lhs);
}
bool number::operator>=(const Fraction& lhs, const Fraction& rhs)
{
    return !operator<(lhs, rhs);
}
bool number::operator<=(const Fraction& lhs, const Fraction& rhs)
{
    return !operator>(lhs, rhs);
}




Fraction number::pow(Fraction fraction, int exp)
{
    Fraction power(1ll, 1ll);
    if (exp < 0)
    {
        fraction = Fraction(1ll, 1ll) / fraction;
        exp = -exp;
    }

    while (exp > 0)
    {
        if (exp & 1) power *= fraction;
        fraction *= fraction;
        exp >>= 1;
    }

    return power;
}

std::ostream& number::operator<<(std::ostream& output, const Fraction& fraction)
{
    if (fraction.numerator_ != 0 && fraction.denominator_ != 1) output << fraction.numerator_ << '/' << fraction.denominator_;
    else output << std::fixed << fraction.numerator_;

    return output;
}