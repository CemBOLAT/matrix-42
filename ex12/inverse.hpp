#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"
#include "../ex11/determinant.hpp"
#include "../ex09/transpose.hpp"


template <typename K>
Matrix<K> Matrix<K>::inverse() const
{
    if (!is_square())
    {
        throw std::invalid_argument("Matrix is not square");
    }

    K det = determinant();
    if (det == K())
    {
        throw std::invalid_argument("Matrix is not invertible");
    }

    Matrix<K> inv = Matrix<K>(m_rows, m_cols);
    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m_cols; j++)
        {
            inv(i, j) = cofactor(i, j) / det;
        }
    }

    return inv.transpose();
}