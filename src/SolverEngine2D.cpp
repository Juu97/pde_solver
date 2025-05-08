// src/SolverEngine2D.cpp

#include "SolverEngine2D.hpp"
#include <iostream>

void SolverEngine2D::run()
{
    size_t nTimesteps = static_cast<size_t> (totalTime_/dt_);

    std::cout << "[SolverEngine2D] Starting simulation for " << nTimesteps << " steps...\n";

    initial_.apply(u_, grid_);

    UnknownField2D rhs(u_.getNx(), u_.getNy(), u_.getNt());

    for (std::size_t t = 0; t < nTimesteps; ++t) {
        double time = t * dt_;

        equation_.computeSpatialOperator(u_, rhs, grid_, t);
        boundary_.apply(rhs, grid_, time, t);
        integrator_.step(u_, rhs, dt_, t);
    }

    std::cout << "[SolverEngine2D] Simulation complete.\n";
}
