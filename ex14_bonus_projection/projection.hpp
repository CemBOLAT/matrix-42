#pragma once

#include "../base/Matrix/Matrix.hpp"
#include "../base/Vector/Vector.hpp"
#include "../ex10/row_echelon_form.hpp"


template <typename K>
Matrix<K> Matrix<K>::projection(K fov, K ratio, K near, K far) const
{
    if (m_rows != 4 || m_cols != 4)
    {
        throw std::invalid_argument("Matrix must be 4x4 to calculate the projection matrix");
    }
    // Fov is defined in degress,
    // Ratio is the aspect ratio of the screen
    // Near is the distance to the near plane
    // Far is the distance to the far plane
    // FOV is the field of view in degrees

    K fov_rad = fov * M_PI / 180.0;
    K 





    
}