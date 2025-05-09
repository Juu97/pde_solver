// src/SolverEngine2D.cpp

#include "SolverEngine2D.hpp"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <fstream>

void SolverEngine2D::run()
{
    size_t nTimesteps = static_cast<size_t>(totalTime_ / dt_);

    std::cout << "[SolverEngine2D] Starting simulation for " << nTimesteps << " steps...\n";

    initial_->apply(u_, *grid_);

    UnknownField2D rhs(u_.getNx(), u_.getNy(), u_.getNt());

    for (std::size_t t = 0; t < nTimesteps; ++t) {
        double time = t * dt_;

        equation_->computeSpatialOperator(u_, rhs, *grid_, t);
        boundary_->apply(rhs, *grid_, time, t);
        integrator_->step(u_, rhs, dt_, t);

        notifyObservers(u_, *grid_, t + 1, (t + 1) * dt_);
    }

    std::cout << "\n[SolverEngine2D] Simulation complete.\n";
}


void SolverEngine2D::addObserver(std::unique_ptr<ISolverObserver> observer)
{
    observers_.push_back(std::move(observer));
}

void SolverEngine2D::notifyObservers(const UnknownField2D& u, const IGrid2D & grid, size_t timestep, double time) const
{
    for (auto& obs : observers_)
        obs->update(u, grid, timestep, time);
}
