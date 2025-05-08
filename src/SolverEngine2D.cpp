// src/SolverEngine2D.cpp

#include "SolverEngine2D.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>

void SolverEngine2D::run()
{
    size_t nTimesteps = static_cast<size_t>(totalTime_ / dt_);

    std::cout << "[SolverEngine2D] Starting simulation for " << nTimesteps << " steps...\n";

    initial_.apply(u_, grid_);

    UnknownField2D rhs(u_.getNx(), u_.getNy(), u_.getNt());

    for (std::size_t t = 0; t < nTimesteps; ++t) {
        double time = t * dt_;

        equation_.computeSpatialOperator(u_, rhs, grid_, t);
        boundary_.apply(rhs, grid_, time, t);
        integrator_.step(u_, rhs, dt_, t);

        // TEST CASE COMPUTATION
        // Compute max absolute error at t+1
        double alpha = 1.0;
        double maxError = 0.0;

        for (std::size_t i = 0; i < u_.getNx(); ++i) {
            for (std::size_t j = 0; j < u_.getNy(); ++j) {
                Coordinates2D coord = grid_.getCoordinates(i, j);
                double x = coord.x;
                double y = coord.y;

                double u_exact = std::sin(M_PI * x) * std::sin(M_PI * y) *
                                 std::exp(-2 * M_PI * M_PI * alpha * (t + 1) * dt_);

                double error = std::abs(u_(i, j, t + 1) - u_exact);
                if (error > maxError) {
                    maxError = error;
                }
            }
        }

        std::cout << "[Timestep " << t << "] Max abs error = " << maxError << "\n";
    }

    std::cout << "\n[SolverEngine2D] Simulation complete.\n";
}
