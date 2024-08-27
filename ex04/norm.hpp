#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"

/**
 * Euclidean norm or L2 norm (SQUARE ROOT OF THE SUM OF THE SQUARES)
 * 
 * << Like a hypotenuse of a triangle >> Length of the vector from the origin or the distance from the origin to the point
 * 
 * @return the Euclidean norm of the vector
 */
template <typename K>
K Vector<K>::norm() const { // Euclidean norm or L2 norm (SQUARE ROOT OF THE SUM OF THE SQUARES)
    K result = K();
    for (size_t i = 0; i < m_size; i++) {
        result += m_data[i] * m_data[i];
    }
    return std::sqrt(result);
}

/**
 * Manhattan norm or L1 norm (ABSOLUTE VALUE)
 * 
 * << Like a city block >> Distance between two points measured along axes at right angles
 * 
 * @return the Manhattan norm of the vector
 */
template <typename K>
K Vector<K>::norm_1() const { // Manhattan norm or L1 norm (ABSOLUTE VALUE)
    K result = K();
    for (size_t i = 0; i < m_size; i++) {
        result += std::abs(m_data[i]);
    }
    return result;
}

/**
 * supremum norm or L-infinity norm (MAXIMUM VALUE)
 * 
 * << Maximum value of Manhattan norm >> Maximum distance between point to axis
 * 
 * @return the supremum norm of the vector
 */
template <typename K>
K Vector<K>::norm_inf() const { // supremum norm or L-infinity norm (MAXIMUM VALUE)
    K result = K();
    for (size_t i = 0; i < m_size; i++) {
        result = std::max(result, std::abs(m_data[i]));
    }
    return result;
}

/**
 * Euclidean norm or L2 norm (SQUARE ROOT OF THE SUM OF THE SQUARES)
 * 
 * << Like a hypotenuse of a triangle >> Length of the vector from the origin or the distance from the origin to the point
 * 
 * @return the Euclidean norm of the vector
 */
template <typename K>
K Vector<K>::norm_complex() const { // Euclidean norm or L2 norm (SQUARE ROOT OF THE SUM OF THE SQUARES)
    K result = K();
    for (size_t i = 0; i < m_size; i++) {
        result += m_data[i].abs() * m_data[i].abs();
    }
    return result.sqrt();
}

/**
 * Manhattan norm or L1 norm (ABSOLUTE VALUE)
 * 
 * << Like a city block >> Distance between two points measured along axes at right angles
 * 
 * @return the Manhattan norm of the vector
 */
template <typename K>
K Vector<K>::norm_1_complex() const { // Manhattan norm or L1 norm (ABSOLUTE VALUE)
    K result = K();
    for (size_t i = 0; i < m_size; i++) {
        result += m_data[i].abs();
    }
    return result;
}

/**
 * supremum norm or L-infinity norm (MAXIMUM VALUE)
 * 
 * << Maximum value of Manhattan norm >> Maximum distance between point to axis
 * 
 * @return the supremum norm of the vector
 */
template <typename K>
K Vector<K>::norm_inf_complex() const { // supremum norm or L-infinity norm (MAXIMUM VALUE)
    K result = K();
    for (size_t i = 0; i < m_size; i++) {
        result = result.max(m_data[i].abs());
    }
    return result;
}