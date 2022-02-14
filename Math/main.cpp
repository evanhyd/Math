#include <iostream>
#include <iomanip>
#include <numbers>
#include <numeric>
#include "debug.h"

#include "Fraction.h"
#include "Vector.h"
#include "Matrix.h"


using namespace number;
using namespace matrix;
using namespace std;

int main()
{
    DEBUG_MEMORY();
    srand(time(NULL));
    
    while (true)
    {
        try
        {
            Fraction f(2ll, 1ll);
            std::cout << f << '\n';
            std::cout << pow(f, -2) << '\n';

            getchar();
        }
        catch (const std::exception &error)
        {
            std::cerr << error.what() << '\n';
        }
    }
}