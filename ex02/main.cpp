#include "linearInterp.hpp"

int main(){
    try
    {
        std::cout << std::fixed << std::setprecision(1)<< lerp(0., 1., 0.) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << lerp(0., 1., 1.) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << lerp(0., 1., 0.5) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << lerp(21., 42., 0.3) << std::endl;

        std::cout << std::endl;

        std::cout << lerp(Vector<double>{2., 1.},
                            Vector<double>{4., 2.}, 0.3) << std::endl;

        std::cout << lerp(Matrix<double>{{2., 1.}, {3., 4.}}, 
                            Matrix<double>{{20., 10.}, {30., 40.}},
                            0.5) << std::endl;

        std::cout << lerp(Matrix<double>{{2., 1.}, {3., 4.}}, 
                            Matrix<double>{{20., 10.}, {30., 40.}},
                            1.5) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}