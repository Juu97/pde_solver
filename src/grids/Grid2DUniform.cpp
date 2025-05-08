#include "Grid2DUniform.hpp"
Grid2DUniform::Grid2DUniform(double Lx, double Ly, int nx, int ny, int x0, int y0)
{

    double dx = Lx / (double) (nx-1);
    double dy = Ly / (double) (ny-1);

    nx_ = nx;
    ny_ = ny;
    x0_ = x0;
    y0_ = y0;
    dx_ = dx;
    dy_ = dy;
    coordinates_.resize(nx * ny);

    for (std::size_t i = 0; i < nx; ++i) {
        for (std::size_t j = 0; j < ny; ++j) {
            double x = x0 + i * dx;
            double y = y0 + j * dy;
            coordinates_[i * ny + j] = {x, y};
        }
    }
}

Coordinates2D Grid2DUniform::getCoordinates(std::size_t i, std::size_t j) const
{
    std::size_t idx = i * ny_ + j;
    return coordinates_[idx];
}
