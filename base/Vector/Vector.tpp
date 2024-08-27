#ifndef VECTOR_TPP
#define VECTOR_TPP

#include <iostream>
#include <sstream>
#include "Vector.hpp"


template <typename K>
Vector<K>::Vector() : m_size(0), m_data(nullptr) {}

template <typename K>
Vector<K>::Vector(const K *data, size_t size) : m_size(size) {
    m_data = new K[m_size];
    if (m_data == nullptr) {
        throw std::bad_alloc();
    }
    for (size_t i = 0; i < m_size; i++) {
        m_data[i] = data[i];
    }
}

template <typename K>
Vector<K>::Vector(const Vector<K> &v) : m_size(v.m_size) {
    m_data = new K[m_size];
    if (m_data == nullptr) {
        throw std::bad_alloc();
    }
    for (size_t i = 0; i < m_size; i++) {
        m_data[i] = v.m_data[i];
    }
}

template <typename K>
Vector<K>::Vector(const std::initializer_list<K>& list) : m_size(list.size()) {
    m_data = new K[m_size];
    if (m_data == nullptr) {
        throw std::bad_alloc();
    }
    size_t i = 0;
    for (const K &elem : list) {
        m_data[i++] = elem;
    }
}

template <typename K>
Vector<K>::~Vector() {
    if (m_data != nullptr) {
        delete[] m_data;
    }
}

template <typename K>
Vector<K> &Vector<K>::operator=(const Vector<K> &v) {
    if (this != &v) {
        if (m_data != nullptr) {
            delete[] m_data;
        }

        m_size = v.m_size;
        m_data = new K[m_size];
        if (m_data == nullptr) {
            throw std::bad_alloc();
        }
        for (size_t i = 0; i < m_size; i++) {
            m_data[i] = v.m_data[i];
        }
    }
    return *this;
}

template <typename K>
size_t Vector<K>::size() const { return m_size; }

template <typename K>
Matrix<K> Vector<K>::reshape(size_t rows, size_t cols) const {
    if (m_size != rows * cols) {
        throw std::invalid_argument("Invalid size");
    }

    Matrix<K> m(rows, cols);
    size_t i = 0;
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            m[r][c] = m_data[i++];
        }
    }
    return m;
}

template <typename K>
K &Vector<K>::operator[](size_t i) {
    if (i >= m_size) {
        throw std::out_of_range("out of range");
    }
    return m_data[i];
}

template <typename K>
const K &Vector<K>::operator[](size_t i) const {
    if (i >= m_size) {
        throw std::out_of_range("out of range");
    }
    return m_data[i];
}

template <typename K>
std::string Vector<K>::trim_trailing_zeros(K value) const {

    std::ostringstream out;
    out << std::fixed << std::setprecision(6) << value;
    std::string str = out.str();

    // Remove trailing zeros
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);

    return str;
}

template <typename K>
std::ostream &operator<<(std::ostream &os, const Vector<K> &v) {
    os << "Vector(" << v.m_size << ")" << std::endl;
    for (size_t i = 0; i < v.m_size; i++) {
        os << "[" << v.trim_trailing_zeros(v.m_data[i]) << "]" << std::endl;
    }
    return os;
}

template <typename K>
Vector<K>::Vector(size_t size) : m_size(size) {
    m_data = new K[m_size];
    if (m_data == nullptr) {
        throw std::bad_alloc();
    }
    for (size_t i = 0; i < m_size; i++) {
        m_data[i] = K();
    }
}

template <typename K>
bool Vector<K>::operator==(const Vector<K> &v) const {
    if (m_size != v.m_size) {
        return false;
    }
    for (size_t i = 0; i < m_size; i++) {
        if (m_data[i] != v.m_data[i]) {
            return false;
        }
    }
    return true;
}

template <typename K>
bool Vector<K>::operator!=(const Vector<K> &v) const {
    return !(*this == v);
}

#endif
