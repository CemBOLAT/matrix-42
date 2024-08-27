#include "Matrix_add_sub_scale.hpp"
#include "Vector_add_sub_scale.hpp"

#include <iostream>

int main(){
    try
    {
        Vector<double> u = Vector<double>({2.2 , 3.});
        Vector<double> v = Vector<double>({5. , 7.});

        std::cout << u + v << std::endl;
        std::cout << u - v << std::endl;
        std::cout << u * 2 << std::endl;

        Matrix<double> m1 = Matrix<double>({
            {1, 2},
            {3, 4}
        });

        Matrix<double> m2 = Matrix<double>({
            {7., 4.},
            {-2., 2.}
        });

        std::cout << m1 + m2 << std::endl;
        std::cout << m1 - m2 << std::endl;
        std::cout << m1 * 2 << std::endl;


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}