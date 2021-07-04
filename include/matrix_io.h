#ifndef RTSOFT_TESTTASK_MATRIX_IO_H
#define RTSOFT_TESTTASK_MATRIX_IO_H

#include <fstream>
#include <vector>

/*
 * Ввод-вывод матрицы из нулей и единиц
 */

/**
 * Ввод сетки
 * @param in - поток ввода
 * @returns введенная сетка
 */
std::vector<std::vector<int8_t>> inputGrid(std::istream &in);

/**
 * Вывод сетки
 * @param out - поток вывода
 * @param grid - ссылка на сетку
 */
void printGrid(std::ostream &out, const std::vector<std::vector<int8_t>> &grid);

#endif //RTSOFT_TESTTASK_MATRIX_IO_H
