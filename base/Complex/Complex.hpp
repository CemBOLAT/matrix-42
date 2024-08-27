#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <iomanip>
#include <initializer_list>

template <typename K>
class Complex {
    public:
        Complex();
        Complex(K real, K imaginary);
        Complex(const Complex<K> &c);
        Complex(const std::initializer_list<K>& list);
        ~Complex();

        Complex<K> &operator=(const Complex<K> &c);
        
        Complex<K> operator+(const Complex<K> &c) const;
        Complex<K> operator-(const Complex<K> &c) const;
        Complex<K> operator*(const Complex<K> &c) const;
        Complex<K> operator/(const Complex<K> &c) const;
        Complex<K> operator*(K k) const;
        Complex<K> operator/(K k) const;
        Complex<K> operator-() const;
        Complex<K> operator+() const;
        bool operator==(const Complex<K> &c) const;
        bool operator!=(const Complex<K> &c) const;

        Complex &operator+=(const Complex<K> &c);
        Complex &operator-=(const Complex<K> &c);
        Complex &operator*=(const Complex<K> &c);
        Complex &operator/=(const Complex<K> &c);
        Complex &operator*=(K k);
        Complex &operator/=(K k);
        bool operator<(const Complex<K> &c) const;
        bool operator<=(const Complex<K> &c) const;
        bool operator>(const Complex<K> &c) const;
        bool operator>=(const Complex<K> &c) const;
        

        template <typename T>
        friend std::ostream &operator<<(std::ostream &os, const Complex<T> &c);
        std::string trim_trailing_zeros(K value) const;

        Complex<K> abs() const;
        Complex<K> sqrt() const;
        Complex<K> max(const Complex<K> &c) const;

    private:
        K m_real;
        K m_imaginary;
};

#include "Complex.tpp"

#endif
