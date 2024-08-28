#include "./projection.hpp"
#include <iostream>
#include <vector>
#include <cmath>

/*

1.0, 0.0, 0.0, 0.0
0.0, 1.0, 0.0, 0.0
0.0, 0.0, 1.0, 0.0
0.0, 0.0, 0.0, 1.0
*/

using namespace std;

int main() {
        Matrix<double> projection = Matrix<double>::projection(M_PI / 2, 1, 1, 100);

    try {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                float val = projection(i, j);
                cout << std::fixed << std::setprecision(1) << val;
                if (j != 3)
                    cout << ", ";
            }
            cout << endl;
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
