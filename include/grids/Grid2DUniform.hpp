#pragma once
#include <vector>
#include "IGrid2D.hpp"

class Grid2DUniform : public IGrid2D {
private:
    std::vector<Coordinates2D> coordinates_;
    std::size_t nx_, ny_;
    double dx_, dy_;
    double x0_, y0_;

public:
    Grid2DUniform() = default;
    Grid2DUniform(double Lx, double Ly, int nx, int ny, int x0, int y0);
    Coordinates2D getCoordinates(std::size_t i, std::size_t j) const override;
};