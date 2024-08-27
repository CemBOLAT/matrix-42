
#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"


template <typename K>
void row_swap(Matrix<K> &m, size_t i, size_t j)
{
    for (size_t k = 0; k < m.cols(); k++)
    {
        std::swap(m(i, k), m(j, k));
    }
}

template <typename K>
void row_mul(Matrix<K> &m, size_t i, K factor)
{
    for (size_t j = 0; j < m.cols(); j++)
    {
        m(i, j) *= factor;
    }
}

template <typename K>
void row_add(Matrix<K> &m, size_t i, size_t j, K factor)
{
    for (size_t k = 0; k < m.cols(); k++)
    {
        m(i, k) += factor * m(j, k);
    }
}

template <typename K>
size_t find_max_abs_in_col(const Matrix<K> &m, size_t col, size_t start_row)
{
    size_t max_row = start_row;

    for (size_t i = start_row + 1; i < m.rows(); i++)
    {
        if (std::abs(m(i, col)) > std::abs(m(max_row, col)))
        {
            max_row = i;
        }
    }

    return max_row;
}


/**
 * @brief Compute the row echelon form of the matrix
 * 
 * Formula: The row echelon form of a matrix is a matrix in which all the elements below the main diagonal are zero
 * 
 * @return Matrix<K> Row echelon form of the matrix
 * 
 */
template <typename K>
Matrix<K> Matrix<K>::row_echelon() const
{
    Matrix<K> result = *this;

    size_t rows_index = 0;
    size_t cols_index = 0;

    while (rows_index < m_rows && cols_index < m_cols)
    {
        // Find the row with the maximum absolute value in the current column
        size_t max_row = find_max_abs_in_col(result, cols_index, rows_index);

        // Swap the current row with the row having the maximum value
        if (result(max_row, cols_index) != K()) // if the pivot is zero go next column
        {
            if (max_row != rows_index)
            {
                row_swap(result, rows_index, max_row);
            }

            // Normalize the pivot row
            K pivot = result(rows_index, cols_index);
            row_mul(result, rows_index, 1.0 / pivot);

            // Eliminate the entries below the pivot
            for (size_t i = rows_index + 1; i < m_rows; i++)
            {
                K factor = result(i, cols_index);
                row_add(result, i, rows_index, -factor);
            }

            //Eliminate the entries above the pivot
            for (size_t i = 0; i < rows_index; i++)
            {
                K factor = result(i, cols_index);
                row_add(result, i, rows_index, -factor);
            }

            rows_index++;
        }

        // Move to the next column
        cols_index++;
    }

    return result;
}


template <typename K>
size_t find_max_abs_in_col_complex(const Matrix<K> &m, size_t col, size_t start_row)
{
    size_t max_row = start_row;

    for (size_t i = start_row + 1; i < m.rows(); i++)
    {
        if (m(i, col).abs() > m(max_row, col).abs())
        {
            max_row = i;
        }
    }

    return max_row;
}

template <typename K>
Matrix<K> Matrix<K>::row_echelon_complex() const
{
    Matrix<K> result = *this;

    size_t rows_index = 0;
    size_t cols_index = 0;

    while (rows_index < m_rows && cols_index < m_cols)
    {
        // Find the row with the maximum absolute value in the current column
        size_t max_row = find_max_abs_in_col_complex(result, cols_index, rows_index);

        // Swap the current row with the row having the maximum value
        if (result(max_row, cols_index) != K()) // if the pivot is zero go next column
        {
            if (max_row != rows_index)
            {
                row_swap(result, rows_index, max_row);
            }

            // Normalize the pivot row
            K pivot = result(rows_index, cols_index);
            row_mul(result, rows_index, K(1.0, 0) / pivot);

            // Eliminate the entries below the pivot
            for (size_t i = rows_index + 1; i < m_rows; i++)
            {
                K factor = result(i, cols_index);
                row_add(result, i, rows_index, -factor);
            }

            //Eliminate the entries above the pivot
            for (size_t i = 0; i < rows_index; i++)
            {
                K factor = result(i, cols_index);
                row_add(result, i, rows_index, -factor);
            }

            rows_index++;
        }

        // Move to the next column
        cols_index++;
    }

    return result;
}
