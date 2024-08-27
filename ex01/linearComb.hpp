#pragma once


#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"

/**
 * Linear combination of vectors
 * @param vectors vectors to combine
 * @param coefficients coefficients of the linear combination
 * 
 * Calculates the linear combination of the vectors using the coefficients
 * Calculation: result00 = vector00 * coefficient00 + vector10 * coefficient10 + ... + vectorN0 * coefficientN0
 * 
 * @throws std::invalid_argument if the vectors have different sizes or if the number of vectors and coefficients is different
 * @return the linear combination of the vectors
 */

template <typename K>
Vector<K> linear_combination(const Vector<Vector<K>> &vectors, const Vector<K> &coefficients)
{
    if (vectors.size() == 0)
    {
        throw std::invalid_argument("No vectors to combine");
    }
    if (vectors.size() != coefficients.size()) // 
    {
        throw std::invalid_argument("Number of vectors and coefficients must be the same");
    }

    Vector<K> result(vectors[0].size());
    for (int i = 0; i < vectors.size(); i++)
    {
        if (vectors[i].size() != result.size())
        {
            throw std::invalid_argument("Vectors must have the same size");
        }
        for (int j = 0; j < vectors[i].size(); j++)
        {
            result[j] += vectors[i][j] * coefficients[i];
        }
    }
    return result;
}