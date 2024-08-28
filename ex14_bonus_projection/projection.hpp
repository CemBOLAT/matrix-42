#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"
#include "../ex10/row_echelon_form.hpp"


template <typename K>
Matrix<K> Matrix<K>::projection(K fov, K ratio, K near, K far)
{
    Matrix<K> projection(4, 4);

    projection(0, 0) = 1 / (tan(fov / 2) * ratio);
    projection(1, 1) = 1 / tan(fov / 2);
    projection(2, 2) = -(far + near) / (far - near);
    projection(2, 3) = -2 * far * near / (far - near);
    projection(3, 2) = -1;

    return projection;
}