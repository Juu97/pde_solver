#pragma once

#include "boundaries/IBoundaryHandler2D.hpp"
#include "equations/IEquationSystem.hpp"
#include "fields/UnknownField2D.hpp"
#include "grids/IGrid2D.hpp"
#include "initialConditions/InitialCondition2D.hpp"
#include "timeIntegrator2D/ITimeIntegrator2D.hpp"
#include "Logger.hpp"

class SolverEngine2D {
private:
    const IGrid2D& grid_;
    double dt_;
    double totalTime_;
    IBoundaryHandler2D& boundary_;
    IEquationSystem& equation_;
    InitialCondition2D& initial_;
    ITimeIntegrator2D& integrator_;
    UnknownField2D u_;

public:
    SolverEngine2D(
        const IGrid2D& grid,
        IEquationSystem& equation,
        IBoundaryHandler2D& boundary,
        ITimeIntegrator2D& integrator,
        InitialCondition2D& initial,
        double dt,
        double totalTime
    )
    : grid_(grid),
    u_(grid.getNx(), grid.getNy(), static_cast<std::size_t>(totalTime / dt) + 1),
    equation_(equation),
    boundary_(boundary),
    integrator_(integrator),
    initial_(initial),
    dt_(dt),
    totalTime_(totalTime)
    {}

    void run();
    const UnknownField2D& getSolution() const {return u_;};

};