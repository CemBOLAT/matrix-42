#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"

// matrix by vector
// matrix by matrix
template <typename K>
K Matrix<K>::cofactor(int row, int col) const
{
    if (m_rows > 4)
    {
        throw std::invalid_argument("Matrix is too big to calculate the cofactor as pdf requested");
    }

    if (m_rows == 3)
    {
        int i = 0;
        int j = 0;
        K data[2][2];
        for (int r = 0; r < m_rows; r++)
        {
            for (int c = 0; c < m_cols; c++)
            {
                if (r != row && c != col)
                {
                    data[i][j] = m_data[r][c];
                    j++;
                    if (j == 2)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    if (m_rows == 4)
    {
        Matrix m = Matrix(3, 3);
        int i = 0;
        int j = 0;
        for (int r = 0; r < m_rows; r++)
        {
            for (int c = 0; c < m_cols; c++)
            {
                if (r != row && c != col)
                {
                    m(i, j) = m_data[r][c];
                    j++;
                    if (j == 3)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
        return m.determinant();
    }
    return K(); // unreachable
}
template <typename K>
K Matrix<K>::determinant() const
{
    if (is_square() == false)
    {
        throw std::invalid_argument("Matrix is not a square so it doesn't have a determinant");
    }

    if (m_rows == 0)
    {
        return K();
    }

    if (m_rows > 4)
    {
        throw std::invalid_argument("Matrix is too big to calculate the determinant as pdf requested");
    }

    if (m_rows == 1)
    {
        return m_data[0][0];
    }

    if (m_rows == 2)
    {
        return m_data[0][0] * m_data[1][1] - m_data[0][1] * m_data[1][0];
    }

    Matrix m = *this;
    K sum = K();
    for (size_t i = 0; i < m_rows; i++)
    {
        sum += m_data[0][i] * m.cofactor(0, i) * (i % 2 == 0 ? 1 : -1);
    }
    return sum;
}