#include <iostream>

#include "matrix_io.h"
#include "solver.h"

int main() {
    std::ifstream infile("input.txt");
    auto grid = inputGrid(infile);

    std::cout << "You entered grid:" << std::endl;
    printGrid(std::cout, grid);

    std::cout << "Max area of an island:" << std::endl << findMaxIslandArea(grid) << std::endl;

    return 0;
}
