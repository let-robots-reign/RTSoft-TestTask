/**
 * Алгоритм решения задачи
 */

#include "solver.h"

constexpr size_t LAND_MARK = 1;
constexpr size_t VISITED_LAND_MARK = 2;

bool isValid(const GridPoint &point, size_t gridWidth, size_t gridHeight, std::vector<std::vector<int8_t>> &grid) {
    const size_t x = point.x;
    const size_t y = point.y;
    return (x >= 0 && y >= 0 && x < gridWidth && y < gridHeight && grid[x][y] == LAND_MARK);
}

size_t findMaxIslandArea(std::vector<std::vector<int8_t>> &grid) {
    size_t width = grid.size();
    size_t height = grid[0].size();
    size_t maxIslandArea = 0;
    for (size_t i = 0; i < width; ++i) {
        for (size_t j = 0; j < height; ++j) {
            if (grid[i][j] == LAND_MARK) {
                maxIslandArea = std::max(maxIslandArea, islandAreaDFS(grid, i, j));
            }
        }
    }
    return maxIslandArea;
}

size_t islandAreaDFS(std::vector<std::vector<int8_t>> &grid, size_t x, size_t y) {
    size_t width = grid.size();
    size_t height = grid[0].size();
    if (!isValid({x, y}, width, height, grid)) {
        return 0;
    }

    /*
     * Вместо отдельного массива visited с посещенными единичными ячейками маркируем на самой сетке
     * Экономим O(N*M) памяти, не используя массив visited
     * Так как из-за изменения grid функция перестает быть "чистой", при необходимости переиспользования grid
     * можно дополнительно заменить VISITED_LAND_MARK на LAND_MARK в конце findMaxIslandArea()
     */
    grid[x][y] = VISITED_LAND_MARK;

    return 1 + islandAreaDFS(grid, x + 1, y) + islandAreaDFS(grid, x - 1, y)
            + islandAreaDFS(grid, x, y + 1) + islandAreaDFS(grid, x, y - 1);
}

size_t islandAreaDFSParallel(std::vector<std::vector<int8_t>> &grid, size_t x, size_t y) {
    return 0;
}
