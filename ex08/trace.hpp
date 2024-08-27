#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"



/**
 * @brief Multiply a matrix by a vector
 * 
 * Formula: trace(A) = a11 + a22 + a33 + ... + ann (sum of the diagonal elements)
 * 
 * @param v Vector to multiply
 * @return Vector<K> Result of the multiplication
 * @throw std::invalid_argument if the size of the vector is different from the number of columns of the matrix
 * 
 */
template <typename K>
K Matrix<K>::trace() const
{
    if (is_square() == false)
    {
        throw std::invalid_argument("Matrix is not a square so it doesn't have a trace");
    }

    K sum = K();
    for (size_t i = 0; i < m_rows; i++)
    {
        sum += m_data[i][i];
    }

    return sum;
}