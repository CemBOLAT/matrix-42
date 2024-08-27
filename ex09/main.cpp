#include "./transpose.hpp"

int main(){
    try
    {
        Matrix<double> u = Matrix<double>({{1., 0.}, {0., 1.}});

        Matrix<double> v = u.transpose();

        std::cout << v << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}