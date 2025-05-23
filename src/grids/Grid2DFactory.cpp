#include "grids/Grid2DFactory.hpp"
#include "grids/Grid2DUniform.hpp"
#include "Logger.hpp"

std::unique_ptr<IGrid2D> Grid2DFactory::create(Grid2DType type)
{
    if (type == Grid2DType::DefaultUniform){
        Logger::info("Creating 2D grid, default uniform distribution.");
        return std::make_unique<Grid2DUniform>(1, 1, 21, 21, 0, 0);
    }
    else {
        Logger::warning("Unsupported Grid2DType in Grid2DFactory::create. Returning a NULL ptr.");
        return nullptr;
    }
}