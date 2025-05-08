// src/grids/Grid2DUniform.cpp
#include "grids/Grid2DUniform.hpp"

Grid2DUniform::Grid2DUniform(double Lx, double Ly, std::size_t nx, std::size_t ny, double x0, double y0)
{
    dx_ = Lx / static_cast<double>(nx - 1);
    dy_ = Ly / static_cast<double>(ny - 1);

    nx_ = nx;
    ny_ = ny;
    x0_ = x0;
    y0_ = y0;
    coordinates_.resize(nx * ny);

    for (std::size_t j = 0; j < ny_; ++j) {
        for (std::size_t i = 0; i < nx_; ++i) {
            double x = x0_ + i * dx_;
            double y = y0_ + j * dy_;
            coordinates_[j * nx_ + i] = {x, y};
        }
    }
}

Coordinates2D Grid2DUniform::getCoordinates(std::size_t i, std::size_t j) const
{
    if (i >= nx_ || j >= ny_) {
        throw std::out_of_range("Grid2DUniform::getCoordinates - index out of bounds");
    }
    return coordinates_[j * nx_ + i];
}