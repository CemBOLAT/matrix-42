#pragma once


#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"

/**
 * Linear interpolation
 * 
 * Calculates the nearest point to t between a and b (a + (b - a) * t) similarity to the line equation
 * 
 * @throws std::invalid_argument if the t is not in the range [0, 1]
 * 
 * @param a first value
 * @param b second value
 * 
 * @return the linear interpolation of a and b
 */
template <typename K>
K lerp(const K &a, const K &b, double t) {
    if (t < 0 || t > 1) {
        throw std::invalid_argument("t must be in the range [0, 1]");
    }
    return a + (b - a) * t;
}


/**
 * Linear interpolation
 * 
 * Calculates the linear interpolation of each element of a and b
 * 
 * @throws std::invalid_argument if the sizes of a and b are different or if t is not in the range [0, 1]
 * 
 * @param a first vector
 * 
 * @return the linear interpolation of a and b
 * 
 */

template <typename K>
Vector<K> lerp(const Vector<K> &a, const Vector<K> &b, double t) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("Invalid size");
    }
    if (t < 0 || t > 1) {
        throw std::invalid_argument("t must be in the range [0, 1]");
    }
    Vector<K> result(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        result[i] = lerp(a[i], b[i], t);
    }
    return result;
}

/**
 * Linear interpolation
 * 
 * Calculates the linear interpolation of each element of a and b
 * 
 * @throws std::invalid_argument if the sizes of a and b are different or if t is not in the range [0, 1]
 * 
 * @param a first matrix
 * 
 * @return the linear interpolation of a and b
 * 
 */
template <typename K>
Matrix<K> lerp(const Matrix<K> &a, const Matrix<K> &b, double t) {
    if (a.is_same_size(b) == false) {
        throw std::invalid_argument("Invalid size");
    }
    if (t < 0 || t > 1) {
        throw std::invalid_argument("t must be in the range [0, 1]");
    }
    Matrix<K> result(a.rows(), a.cols());
    for (size_t i = 0; i < a.rows(); i++) {
        for (size_t j = 0; j < a.cols(); j++) {
            result(i, j) = lerp(a(i, j), b(i, j), t);
        }
    }
    return result;
}