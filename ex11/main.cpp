#include "./determinant.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        Matrix<double> u = Matrix<double>({{1., -1.}, {-1., 1.}});
        std::cout << u.determinant() << std::endl;
        // 0.0

        u = Matrix<double>({{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}});
        std::cout << u.determinant() << std::endl;
        // 8.0

        u = Matrix<double>({{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}});
        std::cout << u.determinant() << std::endl;
        // -174.0

        u = Matrix<double>({{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}});
        std::cout << u.determinant() << std::endl;
        // 1032
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
