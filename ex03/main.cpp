#include "./dot.hpp"

int main(){
    try
    {
        Vector<double> u = Vector<double>({0. , 0.});
        Vector<double> v = Vector<double>({1. , 1.});

        std::cout << u.dot(v) << std::endl;

        u = Vector<double>({1. , 1.});

        std::cout << u.dot(v) << std::endl;

        u = Vector<double>({-1. , 6.});
        v = Vector<double>({3. , 2.});

        std::cout << u.dot(v) << std::endl;

        u = Vector<double>({-5.2 , 6.1});
        v = Vector<double>({3. , 2.});

        std::cout << u.dot(v) << std::endl;

        /**
         * Expected output:
         * [0, 0] . [1, 1] = 0
         * [1, 1] . [1, 1] = 2
         * [-1, 6] . [3, 2] = 9
         * [-5.2, 6.1] . [3, 2] = -15.6 + 12.2 = -3.4
         */

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}