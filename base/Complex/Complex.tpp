#ifndef COMPLEX_TPP
#define COMPLEX_TPP

#include <iostream>
#include <sstream>
#include "Complex.hpp"

template <typename K>
Complex<K>::Complex() : 
    m_real(0), m_imaginary(0) {}

template <typename K>
Complex<K>::Complex(K real, K imaginary) : 
    m_real(real), m_imaginary(imaginary) {}

template <typename K>
Complex<K>::Complex(const Complex<K> &c) : 
    m_real(c.m_real), m_imaginary(c.m_imaginary) {}

template <typename K>
Complex<K>::Complex(const std::initializer_list<K>& list) : 
    m_real(*list.begin()), m_imaginary(*(list.begin() + 1)) {
        if (list.size() != 2) {
            throw std::invalid_argument("Initializer list must have 2 elements");
        }
    }

template <typename K>
Complex<K>::~Complex() {}

template <typename K>
Complex<K> &Complex<K>::operator=(const Complex<K> &c) {
    if (this != &c) {
        m_real = c.m_real;
        m_imaginary = c.m_imaginary;
    }
    return *this;
}

template <typename K>
Complex<K> Complex<K>::operator+(const Complex<K> &c) const {
    return Complex(m_real + c.m_real, m_imaginary + c.m_imaginary);
}

template <typename K>
Complex<K> Complex<K>::operator-(const Complex<K> &c) const {
    return Complex(m_real - c.m_real, m_imaginary - c.m_imaginary);
}

template <typename K>
Complex<K> Complex<K>::operator*(const Complex<K> &c) const {
    K new_real = m_real * c.m_real - m_imaginary * c.m_imaginary;
    K new_imaginary = m_real * c.m_imaginary + m_imaginary * c.m_real;
    return Complex(new_real, new_imaginary);
}

template <typename K>
Complex<K> Complex<K>::operator/(const Complex<K> &c) const {
    K new_real = (m_real * c.m_real + m_imaginary * c.m_imaginary) / (c.m_real * c.m_real + c.m_imaginary * c.m_imaginary);
    K new_imaginary = (m_imaginary * c.m_real - m_real * c.m_imaginary) / (c.m_real * c.m_real + c.m_imaginary * c.m_imaginary);
    return Complex(new_real, new_imaginary);
}

template <typename K>
Complex<K> Complex<K>::operator*(K k) const {
    return Complex(m_real * k, m_imaginary * k);
}

template <typename K>
Complex<K> Complex<K>::operator/(K k) const {
    return Complex(m_real / k, m_imaginary / k);
}

template <typename K>
Complex<K> Complex<K>::operator-() const {
    return Complex(-m_real, -m_imaginary);
}

template <typename K>
Complex<K> Complex<K>::operator+() const {
    return Complex(m_real, m_imaginary);
}

template <typename K>
bool Complex<K>::operator==(const Complex<K> &c) const {
    return m_real == c.m_real && m_imaginary == c.m_imaginary;
}

template <typename K>
bool Complex<K>::operator!=(const Complex<K> &c) const {
    return (*this == c) == false;
}

template <typename K>
std::string Complex<K>::trim_trailing_zeros(K value) const {
    std::string str = std::to_string(value);
    size_t dot = str.find(".");
    if (dot != std::string::npos) {
        size_t end = str.find_last_not_of("0");
        if (end == dot) {
            end--;
        }
        str = str.substr(0, end + 1);
    }
    return str;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Complex<T> &c) {
    os << std::fixed << std::setprecision(2) << c.trim_trailing_zeros(c.m_real) << " ";
    if (c.m_imaginary >= 0) {
        os << "+";
    }
    os << std::fixed << std::setprecision(2) << c.trim_trailing_zeros(c.m_imaginary) << "i";
    return os;
}

template <typename K>
Complex<K> &Complex<K>::operator+=(const Complex<K> &c) {
    m_real += c.m_real;
    m_imaginary += c.m_imaginary;
    return *this;
}

template <typename K>
Complex<K> &Complex<K>::operator-=(const Complex<K> &c) {
    m_real -= c.m_real;
    m_imaginary -= c.m_imaginary;
    return *this;
}

template <typename K>
Complex<K> &Complex<K>::operator*=(const Complex<K> &c) {
    K new_real = m_real * c.m_real - m_imaginary * c.m_imaginary;
    K new_imaginary = m_real * c.m_imaginary + m_imaginary * c.m_real;
    m_real = new_real;
    m_imaginary = new_imaginary;
    return *this;
}

template <typename K>
Complex<K> &Complex<K>::operator/=(const Complex<K> &c) {
    K new_real = (m_real * c.m_real + m_imaginary * c.m_imaginary) / (c.m_real * c.m_real + c.m_imaginary * c.m_imaginary);
    K new_imaginary = (m_imaginary * c.m_real - m_real * c.m_imaginary) / (c.m_real * c.m_real + c.m_imaginary * c.m_imaginary);
    m_real = new_real;
    m_imaginary = new_imaginary;
    return *this;
}

template <typename K>
Complex<K> &Complex<K>::operator*=(K k) {
    m_real *= k;
    m_imaginary *= k;
    return *this;
}

template <typename K>
Complex<K> &Complex<K>::operator/=(K k) {
    m_real /= k;
    m_imaginary /= k;
    return *this;
}

template <typename K>
Complex<K> Complex<K>::abs() const {
    return Complex(sqrt(m_real * m_real + m_imaginary * m_imaginary), 0);
}

template <typename K>
Complex<K> Complex<K>::sqrt() const {
    K r = sqrt((sqrt(m_real * m_real + m_imaginary * m_imaginary) + m_real) / 2);
    K i = sqrt((sqrt(m_real * m_real + m_imaginary * m_imaginary) - m_real) / 2);
    return Complex(r, i);
}

template <typename K>
Complex<K> Complex<K>::max(const Complex<K> &c) const {
    return Complex(std::max(m_real, c.m_real), std::max(m_imaginary, c.m_imaginary));
}

template <typename K>
bool Complex<K>::operator<(const Complex<K> &c) const {
    return m_real < c.m_real && m_imaginary < c.m_imaginary;
}

template <typename K>
bool Complex<K>::operator<=(const Complex<K> &c) const {
    return m_real <= c.m_real && m_imaginary <= c.m_imaginary;
}

template <typename K>
bool Complex<K>::operator>(const Complex<K> &c) const {
    return m_real > c.m_real && m_imaginary > c.m_imaginary;
}

template <typename K>
bool Complex<K>::operator>=(const Complex<K> &c) const {
    return m_real >= c.m_real && m_imaginary >= c.m_imaginary;
}


#endif
