#include "./trace.hpp"

int main(){
    try
    {
        // Trace Calculation Examples
        Matrix<double> u = Matrix<double>({{1., 0.}, {0., 1.}});
        std::cout << u.trace() << std::endl;  // Expected output: 2.0

        u = Matrix<double>({{2., -5., 0.}, {4., 3., 7.}, {-2., 3., 4.}});
        std::cout << u.trace() << std::endl;  // Expected output: 9.0

        u = Matrix<double>({{-2., -8., 4.}, {1., -23., 4.}, {0., 6., 4.}});
        std::cout << u.trace() << std::endl;  // Expected output: -21.0
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}