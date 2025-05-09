#pragma once

#include "ISolverObserver.hpp"
#include <functional>
#include <iostream>
#include <cmath>

class ObserverExactSolution: public ISolverObserver {
    std::function<double(double, double, double)> func_;

public:

    explicit ObserverExactSolution(std::function<double(double, double, double)> f): func_(std::move(f)) {}

    void update(const UnknownField2D& u, const IGrid2D & grid, size_t timestep, double time) override;

    double computeLinfNorm(const UnknownField2D& u, const IGrid2D & grid, size_t timestep, double time) const;
};