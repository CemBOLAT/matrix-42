#include "./inverse.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        Matrix<double> u = Matrix<double>({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
        std::cout << u.inverse() << std::endl;
        // [1.0, 0.0, 0.0]
        // [0.0, 1.0, 0.0]
        // [0.0, 0.0, 1.0]

        u = Matrix<double>({{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}});
        std::cout << u.inverse() << std::endl;
        // [0.5, 0.0, 0.0]
        // [0.0, 0.5, 0.0]
        // [0.0, 0.0, 0.5]

        u = Matrix<double>({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}});
        std::cout << u.inverse() << std::endl;
        // [0.649425287, 0.097701149, -0.655172414]
        // [-0.781609195, -0.126436782, 0.965517241]
        // [0.143678161, 0.074712644, -0.206896552]
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
