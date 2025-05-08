#include <memory>
#include "Logger.hpp"
#include "grids/Grid2DFactory.hpp"

int main() {
    Logger::info("Hello");

    std::unique_ptr<IGrid2D> grid = Grid2DFactory::create(Grid2DType::DefaultUniform);
    std::unique_ptr<IGrid2D> grid2(std::move(grid));
}