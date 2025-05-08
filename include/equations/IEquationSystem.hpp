// include/equations/IEquationSystem.hpp

#pragma once
#include "fields/UnknownField2D.hpp"
#include "grids/IGrid2D.hpp"

class IEquationSystem {
public:
    virtual ~IEquationSystem() = default;

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