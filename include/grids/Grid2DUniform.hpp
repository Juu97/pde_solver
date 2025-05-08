// include/grids/Grid2DUniform.hpp
#pragma once
#include <vector>
#include "IGrid2D.hpp"

class Grid2DUniform : public IGrid2D {
private:
    std::vector<Coordinates2D> coordinates_;
    std::size_t nx_, ny_;
    double x0_, y0_;

public:
    Grid2DUniform() = default;
    Grid2DUniform(double Lx, double Ly, std::size_t nx, std::size_t ny, double x0, double y0);
    Coordinates2D getCoordinates(std::size_t i, std::size_t j) const override;
};