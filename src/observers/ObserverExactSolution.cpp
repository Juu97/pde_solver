#include "observers/ObserverExactSolution.hpp"

void ObserverExactSolution::update(const UnknownField2D &u, const IGrid2D &grid, size_t timestep, double time)
{
    double lInfNorm = computeLinfNorm(u, grid, timestep, time);
    std::cout << "[Timestep " << timestep << "] Max abs error = " << lInfNorm << "\n";
}

double ObserverExactSolution::computeLinfNorm(const UnknownField2D &u, const IGrid2D &grid, size_t timestep, double time) const
{
    double maxError;
    for (std::size_t i = 0; i < u.getNx(); ++i) {
        for (std::size_t j = 0; j < u.getNy(); ++j) {
            Coordinates2D coord = grid.getCoordinates(i, j);
            double x = coord.x;
            double y = coord.y;

            double u_exact = func_(x, y, time);
            double error = std::abs(u(i, j, timestep) - u_exact);
            maxError = std::max(maxError, error);
        }
    }

    return maxError;
}
