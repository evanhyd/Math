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
            
            matrix::Matrix m1(x, y);


            for (int i = 0; i < m1.RowDim(); ++i)
            {
                for (int j = 0; j < m1.ColumnDim(); ++j)
                {
                    m1[i][j] = rand() & 7;
                }
            }

            std::cout << "Before:\n";
            std::cout << m1 << '\n';

            m1.RowSwap(1, 3);
            std::cout << "After:\n";
            std::cout << (m1) << '\n';


            m1.ColumnSwap(1, 3);
            std::cout << "After:\n";
            std::cout << (m1) << '\n';

            m1.RowAdd(2, 10, 0);
            std::cout << "After:\n";
            std::cout << (m1) << '\n';


            m1.ColumnAdd(2, 10, 0);
            std::cout << "After:\n";
            std::cout << (m1) << '\n';

        }
        catch (const std::exception &error)
        {
            std::cerr << error.what() << '\n';
        }
    }
}