#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction::SetPrecision(10);

    while (true)
    {
        try
        {
            /*Fraction::ValueType n1, d1, n2, d2;

            std::cin >> n1 >> d1;
            Fraction f1(n1, d1);

            std::cin >> n2 >> d2;
            Fraction f2(n2, d2);*/

            double n1, n2;
            std::cin >> n1 >> n2;
            Fraction f1(n1), f2(n2);

            std::cout << (f1 < f2) << '\n';
            std::cout << (f1 == f2) << '\n';

        }
        catch (const std::exception &error)
        {
            std::cerr << error.what() << '\n';
        }
    }
}