#ifndef RTSOFT_TESTTASK_SOLVER_H
#define RTSOFT_TESTTASK_SOLVER_H

#include <cstddef>
#include <vector>
#include <cstdint>

/**
 * Алгоритм решения задачи
 */

struct GridPoint {
    size_t x;
    size_t y;
};

/**
 * Проверка корректности координат ячейки и принадлежность ее к типу "суша"
 * @param point - координаты ячейки
 * @param gridWidth - ширина сетки
 * @param gridHeight - высота сетки
 * @param grid - сетка
 * @return корректность ячейки
 */
bool isValid(const GridPoint &point, size_t gridWidth, size_t gridHeight, std::vector<std::vector<int8_t>> &grid);

/**
 * Нахождение максимальной площади среди всех островов
 * @param grid - сетка (матрица) из значений 0 и 1
 * @return число - площадь наибольшего острова
 */
size_t findMaxIslandArea(std::vector<std::vector<int8_t>> &grid);

/**
 * Depth-first search для данного острова
 * По сути, площадь острова, которому принадлежит ячейка (i, j)
 * @param grid - сетка
 * @param i - первая координата сетки
 * @param j - вторая координата сетки
 * @return площадь острова
 */
size_t islandAreaDFS(std::vector<std::vector<int8_t>> &grid, size_t i, size_t j);

/**
 * Функция, аналогичная islandAreaDFS, но использующая потоки
 * @param grid - сетка
 * @param i - первая координата сетки
 * @param j - вторая координата сетки
 * @return площадь острова
 */
size_t islandAreaDFSParallel(std::vector<std::vector<int8_t>> &grid, size_t i, size_t j);

#endif //RTSOFT_TESTTASK_SOLVER_H
