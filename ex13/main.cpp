#include "./rank.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        Matrix<double> u1 = Matrix<double>({
            {1., 0., 0.},
            {0., 1., 0.},
            {0., 0., 1.}
        });
        std::cout << u1.rank() << std::endl; // 3

        Matrix<double> u2 = Matrix<double>({
            {1., 2., 0., 0.},
            {2., 4., 0., 0.},
            {-1., 2., 1., 1.}
        });
        std::cout << u2.rank() << std::endl; // 2

        Matrix<double> u3 = Matrix<double>({
            {8., 5., -2.},
            {4., 7., 20.},
            {7., 6., 1.},
            {21., 18., 7.}
        });
        std::cout << u3.rank() << std::endl; // 3
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
