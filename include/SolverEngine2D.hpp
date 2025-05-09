#pragma once
#include <memory>

#include "boundaries/IBoundaryHandler2D.hpp"
#include "equations/IEquationSystem.hpp"
#include "fields/UnknownField2D.hpp"
#include "grids/IGrid2D.hpp"
#include "initialConditions/InitialCondition2D.hpp"
#include "timeIntegrator2D/ITimeIntegrator2D.hpp"
#include "Logger.hpp"
#include "observers/ISolverObserver.hpp"

class SolverEngine2D {
private:
    double dt_;
    double totalTime_;

    std::unique_ptr<IGrid2D> grid_;
    std::unique_ptr<IBoundaryHandler2D> boundary_;
    std::unique_ptr<IEquationSystem> equation_;
    std::unique_ptr<InitialCondition2D> initial_;
    std::unique_ptr<ITimeIntegrator2D> integrator_;

    UnknownField2D u_;
    std::vector<std::unique_ptr<ISolverObserver>> observers_;

public:
    SolverEngine2D(
        std::unique_ptr<IGrid2D> grid,
        std::unique_ptr<IBoundaryHandler2D> boundary,
        std::unique_ptr<IEquationSystem> equation,
        std::unique_ptr<InitialCondition2D> initial,
        std::unique_ptr<ITimeIntegrator2D> integrator,
        double dt,
        double totalTime
        )
            : grid_(std::move(grid)),
            boundary_(std::move(boundary)),
            equation_(std::move(equation)),
            initial_(std::move(initial)),
            integrator_(std::move(integrator)),
            dt_(dt),
            totalTime_(totalTime),
            u_(0, 0, 0)
        {
            u_ = std::move(UnknownField2D(grid_->getNx(), grid_->getNy(),
                                static_cast<std::size_t>(totalTime_ / dt_) + 1));
        }

    void run();
    const UnknownField2D& getSolution() const {return u_;};
    void exportAllStatesCSV(const std::string& filename) const;
    void addObserver(std::unique_ptr<ISolverObserver> observer);
    void notifyObservers(const UnknownField2D& u, const IGrid2D & grid, size_t timestep, double time) const;


};