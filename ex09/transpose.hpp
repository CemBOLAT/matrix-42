#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"

/**
 * @brief Transpose the matrix
 * 
 * Formula: Matrix[i][j] = Matrix[j][i] for all i,j
 * 
 * @return Matrix<K> Transposed matrix
 * 
 */

template <typename K>
Matrix<K> Matrix<K>::transpose() const
{
    Matrix<K> result = Matrix<K>(m_cols, m_rows);

    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m_cols; j++)
        {
            result(j,i) = m_data[i][j];
        }
    }

    return result;
}