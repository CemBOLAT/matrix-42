#include "./matrix_multiplication.hpp"

int main(){
    try
    {
        Matrix<double> u = Matrix<double>({{1., 0.}, {0., 1.}});
        Vector<double> v = Vector<double>({4., 2.});

        std::cout << u.mul_vec(v) << std::endl;

        u = Matrix<double>({{2., 0.}, {0., 2.}});
        v = Vector<double>({4., 2.});

        std::cout << u.mul_vec(v) << std::endl;


        u = Matrix<double>({{2., -2.}, {-2., 2.}});

        v = Vector<double>({4., 2.});

        std::cout << u.mul_vec(v) << std::endl;

        u = Matrix<double>({{1., 0.}, {0., 1.}});

        Matrix<double> u2 = Matrix<double>({{1., 0.}, {0., 1.}});
        
        std::cout << u.mul_mat(u2) << std::endl;

        u2 = Matrix<double>({{2., 1.}, {4., 2.}});

        std::cout << u.mul_mat(u2) << std::endl;

        u = Matrix<double>({{3., -5.}, 
                            {6., 8.}});

        u2 = Matrix<double>({{2., 1.},
                             {4., 2.}});

        std::cout << u.mul_mat(u2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}