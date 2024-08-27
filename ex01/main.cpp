#include "linearComb.hpp"

int main(){
    try
    {
        Vector<double> v1 = {1.0, 0.0, 0.0};
        Vector<double> v2 = {0.0, 1.0, 0.0};
        Vector<double> v3 = {0.0, 0.0, 1.0};

        Vector<double> v4 = {1., 2., 3.};
        Vector<double> v5 = {0., 10., -100.};

        std::cout << linear_combination(Vector<Vector<double>>{v1, v2, v3}, Vector<double>{10., -2., 0.5}) << std::endl;
        /*
            Output:
            [10, -2, 0.5]
        */
        std::cout << linear_combination(Vector<Vector<double>>{v4, v5}, Vector<double>{10., -2.}) << std::endl;
        /*
            Output:
            [10, 0, 230]
        */

        Vector<double> v6 = {1., 2.2, 3.};
        Vector<double> v7 = {1., 2., 4.2};
        std::cout << linear_combination(Vector<Vector<double>>{v6, v7}, Vector<double>{10., -2.}) << std::endl;
        /*
            Output:
            [8, 18, 21.6]
        */

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}