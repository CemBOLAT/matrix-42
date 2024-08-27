#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"

/**
 * Cross product
 * 
 * Calculates the cross product of two vectors
 * 
 * General formula: u x v = (u2v3 - u3v2, u3v1 - u1v3, u1v2 - u2v1)
 * 
 * @throws std::invalid_argument if the sizes of the vectors are different
 * @throws std::invalid_argument if the size of the vectors is not 3
 * @param u vector
 * @param v vector
 * @return the cross product of the vectors
 */
template <typename K>
Vector<K> cross_product(Vector<K> const &u, Vector<K> const &v)
{
    if (u.size() != 3 || v.size() != 3)
    {
        throw std::invalid_argument("Invalid size");
    }

    Vector<K> result(3);
    result[0] = u[1] * v[2] - u[2] * v[1];
    result[1] = u[2] * v[0] - u[0] * v[2];
    result[2] = u[0] * v[1] - u[1] * v[0];

    return result;
}