#pragma once


#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"
#include "../ex04/norm.hpp"
#include "../ex03/dot.hpp"

/**
 * Cosine of the angle between two vectors
 * 
 *
 * Formula: cos(θ) = (u . v) / (||u|| * ||v||)
 * 
 * @throws std::invalid_argument if the sizes of the vectors are different
 * @param u vector
 * @param v vector
 * @return the cosine of the angle between the vectors
 */
template <typename K>
float angle_cos(const Vector<K>& u, const Vector<K>& v)
{
    if (u.size() != v.size())
    {
        throw std::invalid_argument("Vectors must have the same size");
    }
    if (u == Vector<K>(u.size()) || v == Vector<K>(v.size()))
    {
        return 0; // the angle between the origin and any vector is 0 or 180 degrees
    }

    K dot = u.dot(v);
    K norm_u = u.norm();
    K norm_v = v.norm();

    return dot / (norm_u * norm_v);
}

/**
 * Cosine of the angle between two complex vectors
 * 
 *
 * Formula: cos(θ) = (u . v) / (||u|| * ||v||)
 * 
 * @throws std::invalid_argument if the sizes of the vectors are different
 * @param u vector
 * @param v vector
 * @return the cosine of the angle between the vectors
 */
template <typename K>
Complex<K> angle_cos_complex(const Vector<Complex<K>>& u, const Vector<Complex<K>>& v)
{
    if (u.size() != v.size())
    {
        throw std::invalid_argument("Vectors must have the same size");
    }

    Complex<K> dot = u.dot(v);
    Complex<K> norm_u = u.norm_complex();
    Complex<K> norm_v = v.norm_complex();

    return dot / (norm_u * norm_v);
}