#include "./norm.hpp"

int main(){
    try
    {
        Vector<double> u = Vector<double>({0. , 0., 0.});

        std::cout << u.norm_1() << " " << u.norm() << " " << u.norm_inf() << std::endl;
        // 0 0 0

        u = Vector<double>({1. , 2., 3.});

        std::cout << u.norm_1() << " " << u.norm() << " " << u.norm_inf() << std::endl;
        // 6 3.74166 3

        u = Vector<double>({-1. , -2.});

        std::cout << u.norm_1() << " " << u.norm() << " " << u.norm_inf() << std::endl;
        // 3 2.23607 2

        u = Vector<double>({3. , 4.});

        std::cout << u.norm_1() << " " << u.norm() << " " << u.norm_inf() << std::endl;
        // 7 5 4
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}