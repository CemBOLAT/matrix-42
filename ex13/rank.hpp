#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"
#include "../ex10/row_echelon_form.hpp"


template <typename K>
size_t Matrix<K>::rank() const
{
    Matrix<K> m = row_echelon();
    size_t r = 0;
    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m_cols; j++)
        {
            if (m(i, j) != K())
            {
                r++;
                break;
            }
        }
    }
    return r;
}

template <typename K>
size_t Matrix<K>::rank_complex() const
{
    Matrix<K> m = row_echelon_complex();
    size_t r = 0;
    for (size_t i = 0; i < m_rows; i++)
    {
        for (size_t j = 0; j < m_cols; j++)
        {
            if (m(i, j) != K())
            {
                r++;
                break;
            }
        }
    }
    return r;
}