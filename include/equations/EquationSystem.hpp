// include/equations/EquationSystem.hpp
#pragma once
#include "fields/UnknownField2D.hpp"
#include "grids/IGrid2D.hpp"

class EquationSystem {
public:
    virtual ~EquationSystem() = default;

    // Spatial term on t
    virtual void computeSpatialOperator(
        const UnknownField2D& u,
        UnknownField2D& result,
        const IGrid2D& grid,
        std::size_t tIdx
    ) const = 0;

    virtual void addSourceTerm(
        UnknownField2D& result,
        const IGrid2D& grid,
        double time,
        std::size_t tIdx
    ) const {}
};