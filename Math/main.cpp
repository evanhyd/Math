#include <iostream>
#include <iomanip>
#include <numbers>
#include <numeric>
#include "Matrix.h"


#define DEBUG
#ifdef DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

int main()
{
    #ifdef DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    #endif

    
    while (true)
    {
        try
        {
            int x, y, z;
            std::cin >> x >> y >> z; 
            matrix::Matrix m1(x, y, z), m2{ {1, 2, 3} ,{4, 5, 6}, {7, 8, 9} };

            std::cout << m1 << '\n';
            std::cout << m2 << '\n';
            std::cout << (m1 + m2) << '\n';

        }
        catch (const std::exception &error)
        {
            std::cerr << error.what() << '\n';
        }
    }
}