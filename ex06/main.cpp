#include "./cross_product.hpp"

int main(){
    try
    {
        Vector<double> u = Vector<double>({0., 0., 1.});
        Vector<double> v = Vector<double>({1., 0., 0.});

        std::cout << cross_product(u, v) << std::endl;

        u = Vector<double>({1., 2., 3.});
        v = Vector<double>({4., 5., 6.});

        std::cout << cross_product(u, v) << std::endl;

        u = Vector<double>({4., 2., -3.});
        v = Vector<double>({-2., -5., 16.});

        std::cout << cross_product(u, v) << std::endl;


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}