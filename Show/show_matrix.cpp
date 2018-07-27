#include <iostream>
#include <vector>

void show_matrix(int ord, std::vector<std::vector<double> > Matrix) {

    for (size_t i = 0; i < ord; i++) {
        std::cout << '\n';
        for (size_t j = 0; j < ord; j++) {
            std::cout << Matrix[i][j] << ' ';
        }
    }

    std::cout << '\n' << std::endl;
}
