#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"


/**
 * @brief Multiply a matrix by a vector
 * 
 * @param v Vector to multiply
 * @return Vector<K> Result of the multiplication
 * @throw std::invalid_argument if the size of the vector is different from the number of columns of the matrix
 * 
 */

template <typename K>
Vector<K> Matrix<K>::mul_vec(const Vector<K> &v) const
{
    if (m_cols != v.size())
    {
        throw std::invalid_argument("Invalid size");
    }

    Vector<K> result = Vector<K>(m_rows);

    for (size_t i = 0; i < m_rows; i++)
    {
        K sum = K();
        for (size_t j = 0; j < m_cols; j++)
        {
            sum += m_data[i][j] * v[j];
        }
        result[i] = sum;
    }

    return result;
}

/**
 * @brief Multiply a matrix by another matrix
 * 
 * @param m Matrix to multiply
 * @return Matrix<K> Result of the multiplication
 * @throw std::invalid_argument if the number of columns of the first matrix is different from the number of rows of the second matrix
 * 
 */
template <typename K>
Matrix<K> Matrix<K>::mul_mat(const Matrix<K> &m) const
{
    if (m_cols != m.m_rows)
    {
        throw std::invalid_argument("Invalid size");
    }

    Matrix<K> result = Matrix<K>(m_rows, m.m_cols);

    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m.m_cols; j++)
        {
            K sum = K();
            for (size_t k = 0; k < m_cols; k++)
            {
                sum += m_data[i][k] * m.m_data[k][j];
            }
            result(i,j) = sum;
        }
    }

    return result;
}

/**
 * let u = Matrix::from([
        [3., -5.],
        [6., 8.],
    ]);
    let v = Matrix::from([
        [2., 1.],
        [4., 2.],
    ]);

    matrix 0 0 = [3., -5.] * [2.]
                             [4.]

    matrix 0 1 = [3., -5.] * [1.]
                             [2.]

    matrix 1 0 = [6., 8.] * [2.]
                            [4.]

    matrix 1 1 = [6., 8.] * [1.]
                            [2.]

    matrix 0 0 = 3 * 2 + -5 * 4 = 2
    matrix 0 1 = 3 * 1 + -5 * 2 = -7
    matrix 1 0 = 6 * 2 + 8 * 4 = 44
    matrix 1 1 = 6 * 1 + 8 * 2 = 22
 */