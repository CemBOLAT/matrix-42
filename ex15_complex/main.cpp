#include "../ex00/Vector_add_sub_scale.hpp"
#include "../ex00/Matrix_add_sub_scale.hpp"
#include "../ex01/linearComb.hpp"
#include "../ex02/linearInterp.hpp"
#include "../ex03/dot.hpp"
#include "../ex04/norm.hpp"
#include "../ex05/cosine.hpp"
#include "../ex06/cross_product.hpp"
#include "../ex07/matrix_multiplication.hpp"
#include "../ex08/trace.hpp"
#include "../ex09/transpose.hpp"
#include "../ex10/row_echelon_form.hpp"
#include "../ex11/determinant.hpp"
#include "../ex12/inverse.hpp"
#include "../ex13/rank.hpp"

#include "../base/Complex/Complex.hpp"

#include <iostream>
#include <map>
#include <string>

void ex00();
void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void ex06();
void ex07();
void ex08();
void ex09();
void ex10();
void ex11();
void ex12();
void ex13();

int main(int argc, char const *argv[]){
    if (argc != 2){
        std::cerr << "Usage: ./complex [0-13]" << std::endl;
        return 1;
    }
    std::map<std::string, void(*)()> examples = {
        {"0", ex00},
        {"1", ex01},
        {"2", ex02},
        {"3", ex03},
        {"4", ex04},
        {"5", ex05},
        {"6", ex06},
        {"7", ex07},
        {"8", ex08},
        {"9", ex09},
        {"10", ex10},
        {"11", ex11},
        {"12", ex12},
        {"13", ex13}
    };
    try
    {
        examples.at(argv[1])();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}



void ex00(){
    // Kompleks sayılar ile vektörler
    Vector<Complex<double>> u = Vector<Complex<double>>({
        Complex<double>(2.0, 3.0), 
        Complex<double>(1.0, 4.0)
    });
    
    Vector<Complex<double>> v = Vector<Complex<double>>({
        Complex<double>(5.0, -2.0), 
        Complex<double>(7.0, 1.0)
    });

    std::cout << u + v << std::endl;    // Toplama
    std::cout << u - v << std::endl;    // Çıkarma
    std::cout << u * Complex<double>(2.0, 0.0) << std::endl; // Skalar çarpma

    // Kompleks sayılar ile matrisler
    Matrix<Complex<double>> m1 = Matrix<Complex<double>>({
        {Complex<double>(1.0, 2.0), Complex<double>(2.0, 3.0)},
        {Complex<double>(3.0, 4.0), Complex<double>(4.0, 5.0)}
    });

    Matrix<Complex<double>> m2 = Matrix<Complex<double>>({
        {Complex<double>(7.0, 1.0), Complex<double>(4.0, -1.0)},
        {Complex<double>(-2.0, 3.0), Complex<double>(2.0, -2.0)}
    });

    std::cout << m1 + m2 << std::endl;    // Toplama
    std::cout << m1 - m2 << std::endl;    // Çıkarma
    std::cout << m1 * Complex<double>(2.0, 0.0) << std::endl; // Skalar çarpma
}

void ex01(){
    // Tanımlamalar
    Vector<Complex<double>> v1 = {Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)};
    Vector<Complex<double>> v2 = {Complex<double>(0.0, 1.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)};
    Vector<Complex<double>> v3 = {Complex<double>(0.0, 0.0), Complex<double>(0.0, 1.0), Complex<double>(0.0, 0.0)};

    Vector<Complex<double>> v4 = {Complex<double>(1.0, 1.0), Complex<double>(2.0, -1.0), Complex<double>(3.0, 2.0)};
    Vector<Complex<double>> v5 = {Complex<double>(0.0, 1.0), Complex<double>(10.0, -10.0), Complex<double>(-100.0, 0.0)};

    Vector<Complex<double>> coef1 = {Complex<double>(1.0, 0.0), Complex<double>(2.0, 0.0), Complex<double>(3.0, 0.0)};
    Vector<Complex<double>> coef2 = {Complex<double>(1.0, 0.0), Complex<double>(2.0, 0.0)};

    // Test 1
    auto result1 = linear_combination(Vector<Vector<Complex<double>>>{v1, v2, v3}, coef1);
    std::cout << "Test 1 Result: " << result1 << std::endl;
    // Beklenen Çıktı:
    // (10.0, -2.0), (-2.0, 0.5), (0.0, 0.0)

    // Test 2
    auto result2 = linear_combination(Vector<Vector<Complex<double>>>{v4, v5}, coef2);
    std::cout << "Test 2 Result: " << result2 << std::endl;
    // Beklenen Çıktı:
    // (10.0, -19.0), (10.0, -22.0), (-200.0, 0.0)
}

void ex02(){
    // Scalar testler
    std::cout << std::fixed << std::setprecision(1) << lerp(Complex<double>(0.0, 0.0), Complex<double>(1.0, 1.0), 0.0) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << lerp(Complex<double>(0.0, 0.0), Complex<double>(1.0, 1.0), 1.0) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << lerp(Complex<double>(0.0, 0.0), Complex<double>(1.0, 1.0), 0.5) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << lerp(Complex<double>(21.0, 21.0), Complex<double>(42.0, 42.0), 0.3) << std::endl;

    std::cout << std::endl;

    // Vector testler
    std::cout << lerp(Vector<Complex<double>>{Complex<double>(2.0, 1.0), Complex<double>(1.0, 2.0)},
                      Vector<Complex<double>>{Complex<double>(4.0, 2.0), Complex<double>(2.0, 4.0)},
                      0.3) << std::endl;
    // Beklenen Çıktı:
    // (2.6, 1.3), (1.9, 2.6)

    std::cout << std::endl;

    // Matrix testler
    std::cout << lerp(Matrix<Complex<double>>{{Complex<double>(2.0, 1.0), Complex<double>(1.0, 2.0)},
                                              {Complex<double>(3.0, 4.0), Complex<double>(4.0, 5.0)}},
                      Matrix<Complex<double>>{{Complex<double>(20.0, 10.0), Complex<double>(10.0, 20.0)},
                                              {Complex<double>(30.0, 40.0), Complex<double>(40.0, 50.0)}},
                      0.5) << std::endl;
    // Beklenen Çıktı:
    // (11.0, 5.5), (5.5, 11.0)
    // (16.5, 22.5), (22.0, 27.5)
}

void ex03(){

    Vector<Complex<double>> u = Vector<Complex<double>>({
        Complex<double>(0.0, 0.0), 
        Complex<double>(0.0, 0.0)
    });

    Vector<Complex<double>> v = Vector<Complex<double>>({
        Complex<double>(1.0, 0.0), 
        Complex<double>(1.0, 0.0)
    });

    std::cout << u.dot(v) << std::endl;

    u = Vector<Complex<double>>({
        Complex<double>(1.0, 0.0), 
        Complex<double>(1.0, 0.0)
    });

    std::cout << u.dot(v) << std::endl;

    u = Vector<Complex<double>>({
        Complex<double>(-1.0, 6.0), 
        Complex<double>(3.0, 2.0)
    });

    v = Vector<Complex<double>>({
        Complex<double>(3.0, 2.0), 
        Complex<double>(3.0, 2.0)
    });

    std::cout << u.dot(v) << std::endl;
}

void ex04(){

    Vector<Complex<double>> u = Vector<Complex<double>>({
        Complex<double>(0.0, 0.0), 
        Complex<double>(0.0, 0.0),
        Complex<double>(0.0, 0.0)
    });


    std::cout << u.norm_1_complex() << " " << u.norm_complex() << " " << u.norm_inf_complex() << std::endl;

    u = Vector<Complex<double>>({
        Complex<double>(1.0, 0.0), 
        Complex<double>(2.0, 0.0),
        Complex<double>(3.0, 0.0)
    });

    std::cout << u.norm_1_complex() << " " << u.norm_complex() << " " << u.norm_inf_complex() << std::endl;

    u = Vector<Complex<double>>({
        Complex<double>(-1.0, 6.0), 
        Complex<double>(3.0, 2.0)
    });

    std::cout << u.norm_1_complex() << " " << u.norm_complex() << " " << u.norm_inf_complex() << std::endl;
}

void ex05(){
    Vector<Complex<double>> u = Vector<Complex<double>>({
        Complex<double>(1.0, 0.0), 
        Complex<double>(0.0, 0.0)
    });

    Vector<Complex<double>> v = Vector<Complex<double>>({
        Complex<double>(1.0, 0.0), 
        Complex<double>(0.0, 0.0)
    });

    std::cout << angle_cos_complex(u, v) << std::endl;

    u = Vector<Complex<double>>({
        Complex<double>(1.0, 0.0), 
        Complex<double>(0.0, 0.0)
    });

    v = Vector<Complex<double>>({
        Complex<double>(0.0, 1.0), 
        Complex<double>(0.0, 0.0)
    });

    std::cout << angle_cos_complex(u, v) << std::endl;

    u = Vector<Complex<double>>({
        Complex<double>(-1.0, 6.0), 
        Complex<double>(3.0, 2.0)
    });

    v = Vector<Complex<double>>({
        Complex<double>(3.0, 2.0), 
        Complex<double>(3.0, 2.0)
    });

    std::cout << angle_cos_complex(u, v) << std::endl; // Beklenen Çıktı: 0.9999999999999998
}

void ex06(){
    Vector<Complex<double>> u = Vector<Complex<double>>({
        Complex<double>(1.0, 0.0), 
        Complex<double>(0.0, 0.0),
        Complex<double>(0.0, 0.0)
    });

    Vector<Complex<double>> v = Vector<Complex<double>>({
        Complex<double>(0.0, 1.0), 
        Complex<double>(0.0, 0.0),
        Complex<double>(0.0, 0.0)
    });

    std::cout << cross_product(u, v) << std::endl;

    u = Vector<Complex<double>>({
        Complex<double>(1.0, 0.0), 
        Complex<double>(0.0, 0.0),
        Complex<double>(0.0, 0.0)
    });

    v = Vector<Complex<double>>({
        Complex<double>(0.0, 0.0), 
        Complex<double>(1.0, 0.0),
        Complex<double>(0.0, 0.0)
    });

    std::cout << cross_product(u, v) << std::endl;

    u = Vector<Complex<double>>({
        Complex<double>(1.0, 0.0), 
        Complex<double>(0.0, 0.0),
        Complex<double>(0.0, 0.0)
    });

    v = Vector<Complex<double>>({
        Complex<double>(0.0, 0.0), 
        Complex<double>(0.0, 0.0),
        Complex<double>(1.0, 0.0)
    });

    std::cout << cross_product(u, v) << std::endl;
}

void ex07(){
    Matrix<Complex<double>> u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    Vector<Complex<double>> v = Vector<Complex<double>>({
        Complex<double>(4.0, 0.0), 
        Complex<double>(2.0, 0.0)
    });

    std::cout << u.mul_vec(v) << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(2.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(2.0, 0.0)}
    });

    v = Vector<Complex<double>>({
        Complex<double>(4.0, 0.0), 
        Complex<double>(2.0, 0.0)
    });

    std::cout << u.mul_vec(v) << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(2.0, 0.0), Complex<double>(-2.0, 0.0)},
        {Complex<double>(-2.0, 0.0), Complex<double>(2.0, 0.0)}
    });

    v = Vector<Complex<double>>({
        Complex<double>(4.0, 0.0), 
        Complex<double>(2.0, 0.0)
    });

    std::cout << u.mul_vec(v) << std::endl;


    u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    Matrix<Complex<double>> u2 = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    std::cout << u.mul_mat(u2) << std::endl;

    u2 = Matrix<Complex<double>>({
        {Complex<double>(2.0, 0.0), Complex<double>(1.0, 0.0)},
        {Complex<double>(4.0, 0.0), Complex<double>(2.0, 0.0)}
    });

    std::cout << u.mul_mat(u2) << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(3.0, 0.0), Complex<double>(-5.0, 0.0)},
        {Complex<double>(6.0, 0.0), Complex<double>(8.0, 0.0)}
    });

    u2 = Matrix<Complex<double>>({
        {Complex<double>(2.0, 0.0), Complex<double>(1.0, 0.0)},
        {Complex<double>(4.0, 0.0), Complex<double>(2.0, 0.0)}
    });

    std::cout << u.mul_mat(u2) << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(2.0, 3.0)},
        {Complex<double>(3.0, -3.0), Complex<double>(4.0, 7.0)}
    });

    u2 = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(2.0, 3.0)},
        {Complex<double>(3.0, -3.0), Complex<double>(4.0, 7.0)}
    });

    std::cout << u.mul_mat(u2) << std::endl;
}


void ex08(){
    Matrix<Complex<double>> u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    std::cout << u.trace() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(2.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(2.0, 0.0)}
    });

    std::cout << u.trace() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(2.0, 0.0), Complex<double>(-2.0, 0.0)},
        {Complex<double>(-2.0, 0.0), Complex<double>(2.0, 0.0)}
    });

    std::cout << u.trace() << std::endl;
}

void ex09(){
    Matrix<Complex<double>> u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    std::cout << u.transpose() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(2.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(2.0, 0.0)}
    });

    std::cout << u.transpose() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(2.0, 0.0), Complex<double>(-2.0, 0.0)},
        {Complex<double>(-2.0, 0.0), Complex<double>(2.0, 0.0)}
    });

    std::cout << u.transpose() << std::endl;
}

void ex10()
{

    Matrix<Complex<double>> u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    std::cout << u.row_echelon_complex() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(2.0, 0.0)},
        {Complex<double>(3.0, 0.0), Complex<double>(4.0, 0.0)}
    });

    std::cout << u.row_echelon_complex() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(2.0, 0.0)},
        {Complex<double>(2.0, 0.0), Complex<double>(4.0, 0.0)}
    });

    std::cout << u.row_echelon_complex() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(8.0, 0.0), Complex<double>(5.0, 5.0), Complex<double>(-2.0, 2.0), Complex<double>(4.0, 0.0), Complex<double>(28.0, 0.0)},
        {Complex<double>(4.0, 0.0), Complex<double>(2.5, 2.0), Complex<double>(20.0, 3.0), Complex<double>(4.0, 0.0), Complex<double>(-4.0, 0.0)},
        {Complex<double>(8.0, 0.0), Complex<double>(5.0, 4.0), Complex<double>(1.0, 0.0), Complex<double>(4.0, 0.0), Complex<double>(17.0, 0.0)}
    });

    std::cout << u.row_echelon_complex() << std::endl;
    
}


void ex11()
{

    Matrix<Complex<double>> u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(-1.0, 0.0)},
        {Complex<double>(-1.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    std::cout << u.determinant() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(2.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(2.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(2.0, 0.0)}
    });

    std::cout << u.determinant() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(8.0, 0.0), Complex<double>(5.0, 5.0), Complex<double>(-2.0, 2.0)},
        {Complex<double>(4.0, 0.0), Complex<double>(7.0, 0.0), Complex<double>(20.0, 0.0)},
        {Complex<double>(7.0, 0.0), Complex<double>(6.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    std::cout << u.determinant() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(8.0, 0.0), Complex<double>(5.0, 5.0), Complex<double>(-2.0, 2.0), Complex<double>(4.0, 0.0)},
        {Complex<double>(4.0, 0.0), Complex<double>(2.5, 2.0), Complex<double>(20.0, 3.0), Complex<double>(4.0, 0.0)},
        {Complex<double>(8.0, 0.0), Complex<double>(5.0, 4.0), Complex<double>(1.0, 0.0), Complex<double>(4.0, 0.0)},
        {Complex<double>(28.0, 0.0), Complex<double>(-4.0, 0.0), Complex<double>(17.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    std::cout << u.determinant() << std::endl;

    // use imaginary numbers

    u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 1.0), Complex<double>(-1.0, 1.0)},
        {Complex<double>(-1.0, 1.0), Complex<double>(1.0, 1.0)}
    });

    std::cout << u.determinant() << std::endl;
}

void ex12()
{


    Matrix<Complex<double>> u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    std::cout << u.inverse() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(2.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(2.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(2.0, 0.0)}
    });


    std::cout << u.inverse() << std::endl;

    u = Matrix<Complex<double>>({
        {Complex<double>(8.0, 0.0), Complex<double>(5.0, 5.0), Complex<double>(-2.0, 2.0)},
        {Complex<double>(4.0, 0.0), Complex<double>(7.0, 0.0), Complex<double>(20.0, 0.0)},
        {Complex<double>(7.0, 0.0), Complex<double>(6.0, 0.0), Complex<double>(1.0, 0.0)}
    });


    std::cout << u.inverse() << std::endl;

    // use imaginary numbers

    u = Matrix<Complex<double>>({
        {Complex<double>(1.0, 1.0), Complex<double>(-1.0, 1.0)},
        {Complex<double>(-1.0, 1.0), Complex<double>(1.0, 1.0)}
    });

    std::cout << u.inverse() << std::endl;
}

void ex13()
{
    Matrix<Complex<double>> u1 = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    std::cout << u1.rank_complex() << std::endl;

    Matrix<Complex<double>> u2 = Matrix<Complex<double>>({
        {Complex<double>(1.0, 0.0), Complex<double>(2.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(2.0, 0.0), Complex<double>(4.0, 0.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(-1.0, 0.0), Complex<double>(2.0, 0.0), Complex<double>(1.0, 0.0), Complex<double>(1.0, 0.0)}
    });

    std::cout << u2.rank_complex() << std::endl;

    Matrix<Complex<double>> u3 = Matrix<Complex<double>>({
        {Complex<double>(8.0, 0.0), Complex<double>(5.0, 5.0), Complex<double>(-2.0, 2.0)},
        {Complex<double>(4.0, 0.0), Complex<double>(7.0, 0.0), Complex<double>(20.0, 0.0)},
        {Complex<double>(7.0, 0.0), Complex<double>(6.0, 0.0), Complex<double>(1.0, 0.0)},
        {Complex<double>(21.0, 0.0), Complex<double>(18.0, 0.0), Complex<double>(7.0, 0.0)}
    });

    std::cout << u3.rank_complex() << std::endl;

    // use imaginary numbers

    u2 = Matrix<Complex<double>>({
        {Complex<double>(1.0, 1.0), Complex<double>(2.0, 2.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(2.0, 2.0), Complex<double>(4.0, 4.0), Complex<double>(0.0, 0.0), Complex<double>(0.0, 0.0)},
        {Complex<double>(-1.0, 1.0), Complex<double>(2.0, 2.0), Complex<double>(1.0, 1.0), Complex<double>(1.0, 1.0)}
    });

    std::cout << u2.rank_complex() << std::endl;
}