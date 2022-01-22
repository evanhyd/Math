#include <iostream>
#include <iomanip>
#include <numbers>
#include <numeric>
#include "debug.h"

#include "Vector.h"
#include "Matrix.h"


using namespace matrix;


int main()
{
    DEBUG_MEMORY();
    srand(time(NULL));
    
    while (true)
    {
        try
        {
            int x, y;
            std::cin >> x >> y;

            
            matrix::Matrix m1(x + 1, y, 0.0);
            matrix::Matrix m2(y, x + 3, 0.0);


            for (int i = 0; i < m1.RowDim(); ++i)
            {
                for (int j = 0; j < m1.ColumnDim(); ++j)
                {
                    m1[i][j] = rand() & 7;
                }
            }

            for (int i = 0; i < m2.RowDim(); ++i)
            {
                for (int j = 0; j < m2.ColumnDim(); ++j)
                {
                    m2[i][j] = rand() & 7;
                }
            }

            std::cout << "Before:\n";
            std::cout << m1 << '\n' << m2 << '\n';

            std::cout << "After:\n";
            std::cout << (m1 * m2) << std::endl;

            std::cout << "Power:\n";
            std::cout << matrix::pow(m1, 5) << std::endl;

        }
        catch (const std::exception &error)
        {
            std::cerr << error.what() << '\n';
        }
    }
}