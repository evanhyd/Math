#include <iostream>
#include <iomanip>
#include <numbers>
#include <numeric>
#include "debug.h"

#include "Vector.h"
#include "Matrix.h"


using namespace matrix;

void Test(matrix::Vector&& vec)
{
    std::cout << "change value\n";
    vec[2] = 10;
}

int main()
{
    DEBUG_MEMORY();
    
    while (true)
    {
        try
        {
            int x, y;
            double z;
            std::cin >> x >> y >> z; 
            matrix::Matrix m1(x, y, z), m2{ {2, 1, 1} ,{1, 2, 1}, {1, 1, 2} };

            std::cout << m1 << '\n';
            std::cout << m2 << '\n';
            std::cout << (m1 + m2) << '\n';
            std::cout << m1.IsStandard() << '\n';
            std::cout << (m2 - m1).IsStandard() << '\n';

        }
        catch (const std::exception &error)
        {
            std::cerr << error.what() << '\n';
        }
    }
}