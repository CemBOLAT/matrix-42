#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"

/**
 * Dot product
 * 
 * Calculates the dot product of two vectors
 * 
 * @throws std::invalid_argument if the sizes of the vectors are different
 * @param v vector to calculate the dot product
 * @return the dot product of the vectors
 */
template <typename K>
K Vector<K>::dot(const Vector<K> &v) const {
    if (m_size != v.m_size) {
        throw std::invalid_argument("Invalid size");
    }
    K result = K();
    for (size_t i = 0; i < m_size; i++) {
        result += m_data[i] * v.m_data[i];
    }
    return result;
}


