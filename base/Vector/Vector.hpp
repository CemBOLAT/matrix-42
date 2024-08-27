#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iomanip>
#include <initializer_list>
#include "../Complex/Complex.hpp"

template <typename K>
class Matrix;

template <typename K>
class Vector {
public:
    Vector();
    Vector(const K *data, size_t size);
    Vector(const Vector<K> &v);
    Vector(const std::initializer_list<K>& list);
    Vector(size_t size);
    ~Vector();
    Vector<K> &operator=(const Vector<K> &v);
    
    size_t size() const;

    Matrix<K> reshape(size_t rows, size_t cols) const;

    K &operator[](size_t i);
    const K &operator[](size_t i) const;
    bool operator==(const Vector<K> &v) const;
    bool operator!=(const Vector<K> &v) const;
    
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Vector<U> &v);
    std::string trim_trailing_zeros(K value) const;

    /*
        EX00    
    */

    Vector<K> operator+(const Vector<K> &v) const;
    Vector<K> operator-(const Vector<K> &v) const;
    Vector<K> operator*(const K &k) const;
    
    /*
        EX03
    */

    K dot(const Vector<K> &v) const;

    /*
        EX04
    */
    K norm_1() const;
    K norm() const;
    K norm_inf() const;
    /*
        EX05
    */
    K norm_complex() const;
    K norm_1_complex() const;
    K norm_inf_complex() const;
    
private:
    size_t m_size;
    K *m_data;
};

#include "Vector.tpp"

#endif
