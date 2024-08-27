#ifndef VECTOR_ADD_SUB_SCALE_TPP
#define VECTOR_ADD_SUB_SCALE_TPP

#include "../base/Vector/Vector.hpp"

//=============================================================================
// Methods
//=============================================================================

/*
        Vector<K> operator+(const Vector<K> &m) const;
        Vector<K> operator-(const Vector<K> &m) const;
        Vector<K> operator*(const K &k) const;
*/

template <typename K>
Vector<K> Vector<K>::operator+(const Vector<K> &m) const {
    if (m.size() != m_size) {
        throw std::invalid_argument("Matrices must have the same size");
    }
    Vector<K> result(m.size());
    for (size_t i = 0; i < m.size(); i++) {
        result[i] = m_data[i] + m[i];
    }
    return result;
}

template <typename K>
Vector<K> Vector<K>::operator-(const Vector<K> &m) const {
    if (m.size() != m_size) {
        throw std::invalid_argument("Matrices must have the same size");
    }
    Vector<K> result(m.size());
    for (size_t i = 0; i < m.size(); i++) {
        result[i] = m_data[i] - m[i];
    }
    return result;
}

template <typename K>
Vector<K> Vector<K>::operator*(const K &k) const {
    Vector<K> result(m_size);
    for (size_t i = 0; i < m_size; i++) {
        result[i] = m_data[i] * k;
    }
    return result;
}


#endif