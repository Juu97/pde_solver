// src/equations/HeatEquationSystem.cpp
#include "equations/HeatEquationSystem.hpp"


void HeatEquationSystem::computeSpatialOperator(const UnknownField2D &u,
                                                UnknownField2D &result,
                                                const IGrid2D &grid,
                                                std::size_t tIdx) const
{
    const std::size_t nx = u.getNx();
    const std::size_t ny = u.getNy();

    const double dx = grid.getDx();
    const double dy = grid.getDy();
    const double dx2 = dx * dx;
    const double dy2 = dy * dy;

    assert(tIdx < u.getNt());
    assert(result.getNt() > tIdx);
    assert(result.getNx() == nx && result.getNy() == ny);

    for (std::size_t i = 1; i < nx - 1; ++i) {
        for (std::size_t j = 1; j < ny - 1; ++j) {
            double u_xx = (u(i + 1, j, tIdx) - 2 * u(i, j, tIdx) + u(i - 1, j, tIdx)) / dx2;
            double u_yy = (u(i, j + 1, tIdx) - 2 * u(i, j, tIdx) + u(i, j - 1, tIdx)) / dy2;

            result(i, j, tIdx) = alpha_ * (u_xx + u_yy);
        }
    }
}
