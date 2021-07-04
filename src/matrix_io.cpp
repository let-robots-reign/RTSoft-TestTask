/*
 * Ввод-вывод матрицы из нулей и единиц
 */

#include <cassert>
#include "matrix_io.h"

std::vector<std::vector<int8_t>> inputGrid(std::istream &in) {
    size_t width = 0;
    size_t height = 0;
    in >> width >> height;
    assert(width > 0 && height > 0);

    std::vector<std::vector<int8_t>> grid(height, std::vector<int8_t>(width, 0));

    for (auto &row : grid) {
        for (auto &el : row) {
            /*
             * unfortunately it's necessary:
             * https://stackoverflow.com/questions/24617889/why-does-int8-t-and-user-input-via-cin-shows-strange-result
             */
            int tmp = 0;
            in >> tmp;
            assert(tmp == 0 || tmp == 1);
            el = static_cast<int8_t>(tmp);
        }
    }

    return grid;
}

void printGrid(std::ostream &out, const std::vector<std::vector<int8_t>> &grid) {
    for (const auto &row : grid) {
        for (const auto &el : row) {
            out << static_cast<int>(el) << ' ';
        }
        out << std::endl;
    }
    out << std::flush;
}
