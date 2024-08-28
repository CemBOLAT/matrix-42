#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <iomanip>
#include <initializer_list>

template <typename K>
class Vector;

template <typename K>
class Matrix {
    public:
        Matrix();
        Matrix(const Matrix<K> &m);
        Matrix(size_t rows, size_t cols);
        Matrix(const std::initializer_list<std::initializer_list<K>> &list);
        
        ~Matrix();
        Matrix<K> &operator=(const Matrix<K> &m);
        bool is_square() const;
        bool is_same_size(const Matrix<K> &m) const;

        Vector<K> reshape() const;

        size_t rows() const;
        size_t cols() const;
        
        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &m);
        std::string trim_trailing_zeros(K value) const;

        const K &operator()(size_t i, size_t j) const;
        K &operator()(size_t i, size_t j);

        const K *operator()(size_t i) const;
        K *operator()(size_t i); 

        /*
            EX00
        */
        Matrix<K> operator+(const Matrix<K> &m) const;
        Matrix<K> operator-(const Matrix<K> &m) const;
        Matrix<K> operator*(const K &k) const;

        /*
            EX07
        */
        Vector<K> mul_vec(const Vector<K> &v) const;
        Matrix<K> mul_mat(const Matrix<K> &m) const;

        /*
            EX08
        */
        K trace() const;
        
        /*
            EX09
        */
        Matrix<K> transpose() const;
        /*
            EX10
        */
        Matrix<K> row_echelon() const;
        /*
            EX11
        */
        //fn determinant::<K>(&mut self) -> K;
        K   determinant() const;
        K   cofactor(int row, int col) const;

        /*
            EX12
        */
        Matrix<K> inverse() const;
        /*
            EX13
        */
        size_t rank() const;
        /*
            EX14: Bonus1    
        */
        static Matrix<K> projection(K fov, K ratio, K near, K far);
        /*
            Ex15: Bonus2
        */
        Matrix<K>   row_echelon_complex() const;
        size_t      rank_complex() const;

    private:
        size_t m_rows;
        size_t m_cols;
        K **m_data;
};

#include "Matrix.tpp"

#endif