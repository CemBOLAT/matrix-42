#include "./cosine.hpp"

int main(){
    try
    {
        Vector<double> u = Vector<double>({1. , 0.});
        Vector<double> v = Vector<double>({1. , 0.});

        std::cout << angle_cos(u, v) << std::endl;
        // Expected output: 1

        u = Vector<double>({1. , 0.});
        v = Vector<double>({0. , 1.});

        std::cout << angle_cos(u, v) << std::endl;
        // Expected output: 0

        u = Vector<double>({-1. , 1.});
        v = Vector<double>({1. , -1.});

        std::cout << angle_cos(u, v) << std::endl;
        // Expected output: -1

        u = Vector<double>({2. , 1.});
        v = Vector<double>({4. , 2.});

        std::cout << angle_cos(u, v) << std::endl;
        // Expected output: 1

        u = Vector<double>({1. , 2., 3.});
        v = Vector<double>({4. , 5., 6.});

        std::cout << angle_cos(u, v) << std::endl;
        // Expected output: 0.974631

        u = Vector<double>({0. , 0.});
        v = Vector<double>({4. , 3.});

        std::cout << angle_cos(u, v) << std::endl;
        // Expected output: 0
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}