#include <iostream>
#include <iomanip>
#include <numbers>
#include <numeric>
#include "Fraction.h"
#include "Polar2D.h"


int main()
{
    int prec = 8;

    while (true)
    {
        try
        {
            double x, y;
            std::cin >> x >> y;
            y = y / 180.0 * std::numbers::pi;
            geometry::Polar2D coord0(x, y); 

            std::cin >> x >> y;
            y = y / 180.0 * std::numbers::pi;
            geometry::Polar2D coord1(x, y);
            geometry::Polar2D sum = coord0 + coord1;
            
            std::cout <<std::fixed << std::setprecision(prec) << sum.GetMagnitude() << "    " << sum.GetAngle() << '\n';
        }
        catch (const std::exception &error)
        {
            std::cerr << error.what() << '\n';
        }
    }
}