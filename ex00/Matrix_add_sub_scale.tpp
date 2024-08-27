#ifndef MATRIX_ADD_SUB_SCALE_TPP
#define MATRIX_ADD_SUB_SCALE_TPP

#include "../base/Matrix/Matrix.hpp"


/**
 * @brief Add two matrices
 *
 *  This function adds two matrices together. The matrices must have the same size. (i.e. the same number of rows and columns)
 * 
 * @param m The matrix to add
 * @return The result of the addition
 */
template <typename K>
Matrix<K> Matrix<K>::operator+(const Matrix<K> &m) const {
    if (!is_same_size(m)) {
        throw std::invalid_argument("Matrices must have the same size");
    }
    Matrix<K> result(m_rows, m_cols);
    for (size_t i = 0; i < m_rows; i++) {
        for (size_t j = 0; j < m_cols; j++) {
            result(i, j) = m_data[i][j] + m(i, j);
        }
    }
    return result;
}

/**
 * @brief Subtract two matrices
 *
 *  This function subtracts two matrices. The matrices must have the same size. (i.e. the same number of rows and columns)
 * 
 * @param m The matrix to subtract
 * @return The result of the subtraction
 */
template <typename K>
Matrix<K> Matrix<K>::operator-(const Matrix<K> &m) const {
    if (!is_same_size(m)) {
        throw std::invalid_argument("Matrices must have the same size");
    }
    Matrix<K> result(m_rows, m_cols);
    for (size_t i = 0; i < m_rows; i++) {
        for (size_t j = 0; j < m_cols; j++) {
            result(i, j) = m_data[i][j] - m(i, j);
        }
    }
    return result;
}

/**
 * @brief Multiply a matrix by a scalar
 *
 *  This function multiplies a matrix by a scalar. Each element of the matrix is multiplied by the scalar.
 * 
 * @param k The scalar to multiply by
 * @return The result of the multiplication
 */
template <typename K>
Matrix<K> Matrix<K>::operator*(const K &k) const {
    Matrix<K> result(m_rows, m_cols);
    for (size_t i = 0; i < m_rows; i++) {
        for (size_t j = 0; j < m_cols; j++) {
            result(i, j) = m_data[i][j] * k;
        }
    }
    return result;
}


#endif