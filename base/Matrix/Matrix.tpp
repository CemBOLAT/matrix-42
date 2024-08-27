#ifndef MATRIX_TPP
#define MATRIX_TPP

#include <iostream>
#include <sstream>

#include "Matrix.hpp"


template <typename K>
Matrix<K>::Matrix() 
    : m_rows(0), m_cols(0), m_data(nullptr) {}


template <typename K>
Matrix<K>::Matrix(const Matrix<K> &m) {
    m_rows = m.m_rows;
    m_cols = m.m_cols;
    m_data = new K*[m_rows];
    if (m_data == nullptr) {
        throw std::bad_alloc();
    }
    for (size_t i = 0; i < m_rows; i++) {
        m_data[i] = new K[m_cols];
        if (m_data[i] == nullptr) {
            throw std::bad_alloc();
        }
        for (size_t j = 0; j < m_cols; j++) {
            m_data[i][j] = m.m_data[i][j];
        }
    }
}

template <typename K>
Matrix<K>::Matrix(size_t rows, size_t cols) : m_rows(rows), m_cols(cols) {
        m_data = new K*[m_rows];
        if (m_data == nullptr) {
            throw std::bad_alloc();
        }
        for (size_t i = 0; i < m_rows; i++) {
            m_data[i] = new K[m_cols];
            if (m_data[i] == nullptr) {
                throw std::bad_alloc();
            }
            for (size_t j = 0; j < m_cols; j++)
                m_data[i][j] = K();
        }
    }

template <typename K>
Matrix<K>::Matrix(const std::initializer_list<std::initializer_list<K>> &list) {
    m_rows = list.size();
    m_data = new K*[m_rows];
    if (m_data == nullptr) {
        throw std::bad_alloc();
    }
    m_cols = list.begin()->size();
    size_t i = 0;
    for (const std::initializer_list<K> &row : list) {
        if (row.size() != m_cols) {
            throw std::invalid_argument("Invalid size");
        }
        m_data[i] = new K[m_cols];
        if (m_data[i] == nullptr) {
            throw std::bad_alloc();
        }
        size_t j = 0;
        for (const K &elem : row) {
            m_data[i][j++] = elem;
        }
        i++;
    }
}

template <typename K>
Matrix<K>::~Matrix() {
    if (m_data != nullptr) {
        for (size_t i = 0; i < m_rows; i++) {
            delete[] m_data[i];
        }
        delete[] m_data;
    }
}

template <typename K>
bool Matrix<K>::is_square() const { return m_rows == m_cols; }

template <typename K>
bool Matrix<K>::is_same_size(const Matrix<K> &m) const { return m_rows == m.m_rows && m_cols == m.m_cols; }

template <typename K>
Matrix<K> &Matrix<K>::operator=(const Matrix<K> &m) {
    if (this != &m) {
        if (m_data != nullptr) {
            for (size_t i = 0; i < m_rows; i++) {
                delete[] m_data[i];
            }
            delete[] m_data;
        }

        m_rows = m.m_rows;
        m_cols = m.m_cols;
        m_data = new K*[m_rows];
        if (m_data == nullptr) {
            throw std::bad_alloc();
        }
        for (size_t i = 0; i < m_rows; i++) {
            m_data[i] = new K[m_cols];
            if (m_data[i] == nullptr) {
                throw std::bad_alloc();
            }
            for (size_t j = 0; j < m_cols; j++) {
                m_data[i][j] = m.m_data[i][j];
            }
        }
    }
    return *this;
}


// Helper function to trim trailing zeros for any numeric type
template <typename K>
std::string Matrix<K>::trim_trailing_zeros(K value) const {

    std::ostringstream out;
    out << std::fixed << std::setprecision(6) << value;
    std::string str = out.str();

    // Remove trailing zeros
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);

    return str;
}


template <typename K>
std::ostream &operator<<(std::ostream &os, const Matrix<K> &m) {
    os << "Matrix(" << m.m_rows << ", " << m.m_cols << "):" << std::endl;

    for (size_t i = 0; i < m.m_rows; ++i) {
        os << "[";
        for (size_t j = 0; j < m.m_cols; ++j) {
            os << m.trim_trailing_zeros(m.m_data[i][j]);
            if (j < m.m_cols - 1) {
                os << ", ";
            }
        }
        os << "]" << std::endl;
    }
    return os;
}
template <typename K>
Vector<K> Matrix<K>::reshape() const {
    Vector<K> v;
    for (size_t i = 0; i < m_rows; i++) {
        for (size_t j = 0; j < m_cols; j++) {
            v.push_back(m_data[i][j]);
        }
    }
    return v;
}

template <typename K>
size_t Matrix<K>::rows() const { return m_rows; }

template <typename K>
size_t Matrix<K>::cols() const { return m_cols; }

template <typename K>
const K &Matrix<K>::operator()(size_t i, size_t j) const {
    if (i >= m_rows || j >= m_cols) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[i][j];
}

template <typename K>
K &Matrix<K>::operator()(size_t i, size_t j) {
    if (i >= m_rows || j >= m_cols) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[i][j];
}

template <typename K>
const K *Matrix<K>::operator()(size_t i) const {
    if (i >= m_rows) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[i];
}

template <typename K>
K *Matrix<K>::operator()(size_t i) {
    if (i >= m_rows) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[i];
}

#endif
