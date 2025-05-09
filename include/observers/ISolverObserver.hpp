// include/observers/ISolverObserver.hpp

#pragma once
#include "fields/UnknownField2D.hpp"
#include "grids/IGrid2D.hpp"

class ISolverObserver {
public:
    virtual void update(const UnknownField2D& u, const IGrid2D & grid, size_t timestep, double time) = 0;
    virtual ~ISolverObserver() = default;
};